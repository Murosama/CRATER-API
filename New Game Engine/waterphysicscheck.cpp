#include ResourceWater.h

float CalculateDensity(Vector2 samplePoint)
{
	float density = 0;
	const float mass = 1;

	foreach (Vector2 position in position)
	{
		float dst = (position - samplePoint).magnitude
		float influence = SomethingKerne(dst, somethingRadius);
		density += mass * influence;
	}
	
	return density;
}