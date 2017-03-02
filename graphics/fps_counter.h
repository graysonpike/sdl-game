#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#define NUM_FRAMES_SAMPLED (10)
// Interval in seconds before updating FPS calculation
#define UPDATE_DELAY (0.25f)

class FPSCounter {

private:
	float frame_times[NUM_FRAMES_SAMPLED];
	int frame_counter;

	float update_timer;

	float get_average();

public:
	FPSCounter();

	void count(float delta);

	~FPSCounter();
};

#endif