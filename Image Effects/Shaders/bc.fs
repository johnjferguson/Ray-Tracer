// ==========================================================================
// Vertex program for barebones GLFW boilerplate
//
// Author:  Sonny Chan, University of Calgary
// Date:    December 2015
// ==========================================================================
#version 410

// first output is mapped to the framebuffer's colour index by default
out vec4 FragmentColour;

uniform vec3 scolor;

void main(void)
{
    // write colour output without modification
    FragmentColour = vec4(scolor, 1.0);
}