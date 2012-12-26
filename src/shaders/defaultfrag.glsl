uniform vec4 color;
uniform sampler2D tex;
uniform float hasTex;

void main() {
	gl_FragColor = (hasTex * texture2D(tex, gl_TexCoord[0].st) * color) + ((1.0f - hasTex) * color);
}