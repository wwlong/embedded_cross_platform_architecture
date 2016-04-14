/*
*time.c
*time management
*时间的管理,计时器使用
*/

 /*
	function :
		获取系统启动时间 us
	input :
	return value :
		success : 返回从开机到目前的绝对时间
		fail : 	返回0
*/

#include "crs_types.h"

extern int64_t crs_update_time()
{
	int64_t timecnt = xTaskGetTickCount();
	return timecnt * 1000;
}

  /*
	function :
		睡眠 单位us
	input :
		uint32_t microseconds ：所需要睡眠的时间
	return value :
		success : 当前task会让出cpu，在睡眠microseconds后继续运行
		fail :
	FreeRTOS延时最少到1ms即1000us，故此处最少为1000
*/

extern uint32_t crs_usleep(uint32_t microseconds)
{
	vTaskDelay( microseconds / 1000);
	return 1;
}
