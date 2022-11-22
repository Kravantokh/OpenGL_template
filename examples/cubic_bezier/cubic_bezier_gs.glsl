#version 410 core

layout (lines_adjacency) in;
layout (line_strip, max_vertices=32) out;

void main(){
	gl_Position = gl_in[0].gl_Position;
	EmitVertex();
	
	for(int i = 1; i<=31; i++){
		float t = float(i) * 1/30;
		gl_Position = vec4(
			gl_in[0].gl_Position.x*(1-t)*(1-t)*(1-t) + 3*gl_in[1].gl_Position.x*(1-t)*(1-t)*t + 3*gl_in[2].gl_Position.x*(1-t)*t*t + gl_in[3].gl_Position.x*t*t*t,
			gl_in[0].gl_Position.y*(1-t)*(1-t)*(1-t) + 3*gl_in[1].gl_Position.y*(1-t)*(1-t)*t + 3*gl_in[2].gl_Position.t*(1-t)*t*t + gl_in[3].gl_Position.y*t*t*t,
			0,
			1
		);			
		EmitVertex();
	}

	gl_Position = gl_in[3].gl_Position;
	EmitVertex();
	EndPrimitive();
}

