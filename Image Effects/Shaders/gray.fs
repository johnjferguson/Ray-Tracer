#version 410 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform vec4 gray0;

void main()
{
	float grayscale = dot(texture(texture1, TexCoord), gray0);
	FragColor = vec4(grayscale);
}
