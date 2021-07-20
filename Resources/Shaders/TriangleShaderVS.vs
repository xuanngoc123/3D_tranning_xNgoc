attribute vec3 a_posL;
attribute vec2 a_uv;
uniform mat4 u_MVP;
uniform mat4 u_view;
uniform mat4 u_projection;
varying vec2 v_uv;

void main()
{
	vec4 posL = vec4(a_posL, 2.0);
	gl_Position = u_projection * u_view * u_MVP * posL  ;
	v_uv = a_uv;
}
