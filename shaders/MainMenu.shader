shader_type canvas_item;

uniform bool Animate = true;
uniform float GridSize = 15.;
uniform float FlickerSpeed = .6;
uniform float ColorSpeed = 2.;
uniform float PI = 3.14159265;

vec2 Rot(vec2 p, float a) {
	float s = sin(a);
	float c = cos(a);
	return p * mat2(vec2(c, s), vec2(-s, c));
}

float N21(vec2 p)
{
	vec3 p3  = fract(vec3(p.xyx*1500.) * .1031);
    p3 += dot(p3, p3.yzx + 33.33);
    return fract((p3.x + p3.y) * p3.z);
}

float N21Old(vec2 p) {
   return fract( sin(p.x * 100. + p.y*6574.)*5647.);
}

float HexDist(vec2 p) {
	p = abs(p);
	
	float c = dot(p, normalize(vec2(1, 1.73)));
	c = max(c, p.x);
	
	return c;
}

vec4 HexCoords (vec2 uv, float t) {
	uv *= GridSize;
	vec2 r = vec2(1., 1.73);
	vec2 h = r/2.;
	vec2 a = mod(uv, r)-h;
	vec2 b = mod(uv-h, r)-h;
	
	//get closest grid cell
	vec2 gv = dot(a,a) < dot(b,b) ? a : b;

	//float angle = mix(0, 2.*PI, fract(t*.001));
	//gv = Rot(gv, angle);
	
	float x = atan(gv.x, gv.y);
	float y = .5 - HexDist(gv);
	vec2 id = uv - gv;
	return vec4(x, y, id);
}

void fragment() {
	vec2 uv = vec2(UV.x, 1.-UV.y)-.5;
	vec3 col = vec3(0);
	float t = float(Animate) * TIME;

	// float d = sin(3.*HexDist(uv) + t);
	// float near = smoothstep(.2, .22, d);
	// float far = smoothstep(.3, .25, d);
	
	// col *= near * far;

	vec4 hc = HexCoords(uv, t);
	float fade = 2. * hc.y *
		pow(
			sin(100.*N21(hc.zw) + t*FlickerSpeed),
		4);
	float c = smoothstep(.0, .1, fade);

	col = 0.5 + 0.5*cos(ColorSpeed*t+hc.zwz+vec3(0,2,4));
	col *= c;
	
	//col = vec3(uv, 0);
	//col = vec3(hc.zw*.05, 0);
	//col = vec3(N21(hc.zw));

	COLOR = vec4(col, 1.0);
}