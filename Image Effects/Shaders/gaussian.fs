#version 410 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform int ngaus;

// hard coding the pixel offset.. should uniform it in...
float offset = 1.0 / 1000.0;
int radius = (ngaus - 1) / 2;
float sigma = float(radius) / 2.0;
float g = (1 / (2*3.1415*pow(sigma,2)));

void main()
{
	vec3 sum = vec3(0.0);

	for (int i = 0; i < ngaus; i++)
	{
		for (int j = 0; j < ngaus; j++)
		{
			vec3 temp = vec3(texture(texture1, TexCoord + vec2(i*offset - radius*offset, j*offset - radius*offset)));
			sum += temp * g * pow(2.7182, -(pow(abs(i - radius),2) + pow(abs(j - radius),2))/ (2*pow(sigma,2)));
		}
	}

	FragColor = vec4(sum, 0.0);
} 
