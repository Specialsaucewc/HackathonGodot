shader_type canvas_item;

uniform bool Animate = true;
uniform float PI = 3.14159265;

float HexDist(vec2 p) {
	p = abs(p);

	float c = dot(p, normalize(vec2(1, 1.73)));
	c = max(c, p.x);

	return c;
}

vec2 Rot(vec2 p, float a) {
	float s = sin(a);
	float c = cos(a);
	return p * mat2(vec2(c, s), vec2(-s, c));
}

void fragment() {
	vec2 uv = UV - .5;
	vec3 col = vec3(0);
	float t = float(Animate) * TIME;

	//									modulate direction
	float angle = mix(0, 2. * PI, t * .1);
	uv = abs(Rot(uv, angle));
	col = vec3(uv, 0);

	float d = sin(3. * HexDist(uv) + t);
	float near = smoothstep(.2, .22, d);
	float far = smoothstep(.3, .25, d);

	col = 0.5 + 0.5 * cos(t + uv.xyx + vec3(0, 2, 4));
	col *= near * far;

	COLOR = vec4(col, 1.0);
}