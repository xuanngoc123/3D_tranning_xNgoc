attribute vec3 a_posL;
attribute vec3 a_color;
varying vec3 ourColor;
void main()
{
	vec4 posL = vec4(a_posL, 1.0);
	gl_Position = posL;
	ourColor = a_color;
}
   