#version 410 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform vec4 gray0;

void main()
{
	FragColor = texture(texture1, TexCoord);
}
