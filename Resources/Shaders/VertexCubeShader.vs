attribute vec3 a_posL;
uniform mat4 u_MVP;
uniform mat4 u_view;
uniform mat4 u_projection;
varying vec3 v_pos;
void main(void)
{
	gl_Position = u_projection * u_view * u_MVP * vec4(a_posL, 2.0);
	v_pos = a_posL;
}