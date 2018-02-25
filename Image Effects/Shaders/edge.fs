#version 410 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform mat3 sobel;

// hard coding the pixel offset.. should uniform it in...
float offset = 1.0 / 1000.0;

void main()
{
	float sum = 0.0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			vec3 temp = vec3(texture(texture1, TexCoord + vec2(i*offset - offset, j*offset - offset)));
			sum += dot(temp, vec3(0.333, 0.333, 0.333)) * sobel[i][j];
		}
	}

	FragColor = vec4(vec3(abs(sum)), 1.0);
} 
