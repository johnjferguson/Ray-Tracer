#version 410 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;

void main()
{
// algorithm from https://www.techrepublic.com/blog/how-do-i/how-do-i-convert-images-to-grayscale-and-sepia-tone-using-c/

	float red = dot(texture(texture1, TexCoord), vec4(0.393, 0.769, 0.189, 0.000));
	float green = dot(texture(texture1, TexCoord), vec4(0.349, 0.686, 0.168, 0.000));
	float blue = dot(texture(texture1, TexCoord), vec4(0.272, 0.534, 0.131, 0.000));
	FragColor = vec4(red, green, blue, 1.0);
}
