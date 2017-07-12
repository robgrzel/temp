//
// Created by robgrzel on 21.04.17.
//

#ifndef UTILS_SHADER_UTILS_H
#define UTILS_SHADER_UTILS_H

	#include <GL/glew.h>

extern char* file_read(const char* filename, int* size);
extern void print_log(GLuint object);
extern GLuint create_shader(const char* filename, GLenum type);
extern GLuint create_program(const char* vertexfile, const char *fragmentfile);
extern GLuint create_gs_program(const char* vertexfile, const char *geometryfile, const char *fragmentfile, GLint input, GLint output, GLint vertices);
extern GLint get_attrib(GLuint program, const char *name);
extern GLint get_uniform(GLuint program, const char *name);
extern void print_opengl_info();


#endif //UTILS_SHADER_UTILS_H
