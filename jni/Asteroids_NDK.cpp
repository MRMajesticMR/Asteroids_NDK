#include <jni.h>
#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "objects/headers/Ship.h"

#define  LOG_TAG    "libgl2jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#define VIEW_SCALE_FACTOR 1.6f

static void checkGlError(const char* op) {
	for (GLint error = glGetError(); error; error = glGetError()) {
		LOGI("after %s() glError (0x%x)\n", op, error);
	}
}

static const char gVertexShader[] =
		"attribute vec4 vPosition;\n"
		"attribute vec4 vRotation;\n"
		"attribute float angle;\n"
		"attribute float view_scale_factor;\n"
		"void main() {\n"
		"  float PI = 3.14159265358979323846264;\n"
		"  float rad_angle = angle*PI/180.0;\n"
		"  mat4 view_translation = mat4(\n"
		"   vec4(1.0, 0.0, 0.0, 0.0),\n"
		"   vec4(0.0, 1.0, 0.0, -2.1),\n"
		"   vec4(0.0, 0.0, 1.0, 0.0),\n"
		"   vec4(0.0, 0.0, 0.0, 1.0)\n"
		"    );"
		"  mat4 view_scale = mat4(\n"
		"   vec4(0.3 * view_scale_factor, 	0.0, 						0.0, 0.0),\n"
		"   vec4(0.0, 						0.3,					 	0.0, 0.0),\n"
		"   vec4(0.0, 						0.0, 						1.0, 0.0),\n"
		"   vec4(0.0, 						0.0, 						0.0, 1.0)\n"
		"    );"
		"  vec4 a = vPosition;\n"
		"  vec4 b = a;\n"
		"  b.x = a.x*cos(rad_angle) - a.y*sin(rad_angle);\n"
		"  b.y = a.y*cos(rad_angle) + a.x*sin(rad_angle);\n"
		"  b.z = 1.0f;\n"
		"  gl_Position = b * view_translation * view_scale;\n"
		"}\n";

static const char gFragmentShader[] =
		"precision mediump float;\n"
		"void main() {\n"
		"  gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
		"}\n";

GLuint loadShader(GLenum shaderType, const char* pSource) {
	GLuint shader = glCreateShader(shaderType);
	if (shader) {
		glShaderSource(shader, 1, &pSource, NULL);
		glCompileShader(shader);
		GLint compiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled) {
			GLint infoLen = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
			if (infoLen) {
				char* buf = (char*) malloc(infoLen);
				if (buf) {
					glGetShaderInfoLog(shader, infoLen, NULL, buf);
					LOGE("Could not compile shader %d:\n%s\n", shaderType, buf);
					free(buf);
				}
				glDeleteShader(shader);
				shader = 0;
			}
		}
	}
	return shader;
}

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource) {
	GLuint vertexShader = loadShader(GL_VERTEX_SHADER, pVertexSource);
	if (!vertexShader) {
		return 0;
	}

	GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);
	if (!pixelShader) {
		return 0;
	}

	GLuint program = glCreateProgram();
	if (program) {
		glAttachShader(program, vertexShader);
		checkGlError("glAttachShader");
		glAttachShader(program, pixelShader);
		checkGlError("glAttachShader");
		glLinkProgram(program);
		GLint linkStatus = GL_FALSE;
		glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
		if (linkStatus != GL_TRUE) {
			GLint bufLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
			if (bufLength) {
				char* buf = (char*) malloc(bufLength);
				if (buf) {
					glGetProgramInfoLog(program, bufLength, NULL, buf);
					LOGE("Could not link program:\n%s\n", buf);
					free(buf);
				}
			}
			glDeleteProgram(program);
			program = 0;
		}
	}
	return program;
}

GLuint gProgram;

bool setupGraphics(int w, int h) {
	gProgram = createProgram(gVertexShader, gFragmentShader);

	if (!gProgram) {
		LOGE("Could not create program.");
		return false;
	}

	glViewport(0, 0, w, h);
	checkGlError("glViewport");

	return true;
}

Ship* player_ship;

void init_objects()
{
	player_ship = new Ship(0.0f, 0.0f);
}

void clear_screen()
{
	glClearColor(0, 0, 0, 1.0f);
	checkGlError("glClearColor");

	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	checkGlError("glClear");
}

void renderFrame()
{
	clear_screen();

	glUseProgram(gProgram);
	checkGlError("glUseProgram");

	GLuint view_scale_factor_attrib 	= glGetAttribLocation(gProgram, "view_scale_factor");
	glVertexAttrib1f(view_scale_factor_attrib, VIEW_SCALE_FACTOR);

	player_ship->draw(gProgram);
}

extern "C" {
	JNIEXPORT void JNICALL Java_ru_majestic_asteroids_GL2JNILib_init(JNIEnv * env, jobject obj, jint width, jint height);
	JNIEXPORT void JNICALL Java_ru_majestic_asteroids_GL2JNILib_step(JNIEnv * env, jobject obj);
};

JNIEXPORT void JNICALL Java_ru_majestic_asteroids_GL2JNILib_init(JNIEnv * env, jobject obj, jint width, jint height) {
	setupGraphics	(width, height);
	init_objects	();
}

JNIEXPORT void JNICALL Java_ru_majestic_asteroids_GL2JNILib_step(JNIEnv * env, jobject obj) {
	renderFrame();
}
