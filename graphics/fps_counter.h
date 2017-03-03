#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#define NUM_FRAMES_SAMPLED (10)
// Interval in seconds before updating FPS calculation
#define UPDATE_DELAY (0.25f)

class FPSCounter {

	float frame_times[NUM_FRAMES_SAMPLED];
	int frame_counter;
	float update_timer;
	float fps;

	float get_average();

public:
	FPSCounter();
	void count(float delta);
	float get_fps();
	
};

#endif