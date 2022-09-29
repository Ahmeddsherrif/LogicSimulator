#ifndef _TRACE_H_
#define _TRACE_H_

#define IS_TRACE_ACTIVE		1

#if (IS_TRACE_ACTIVE == 1)
	#define TRACE_PRINT(x)	std::cout <<"$$$$ "<< x << std::endl
#else
	#define TRACE_PRINT(x)
#endif	/*IS_TRACE_ACTIVE*/

#endif /*TRACE_H_*/
