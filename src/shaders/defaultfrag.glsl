uniform vec4 color;
uniform sampler2D tex;

void main() {
	vec4 texel;

	texel = texture2D(tex, gl_TexCoord[0].st);

	gl_FragColor = vec4(texel.xyz * color.xyz, texel.w * color.w);
}