#include "TProc.h"
#include "TJobStream.h"
#include <gtest.h>

TEST(TProc, can_create_proc)
{
	ASSERT_NO_THROW(TProc st(0.6, 7, 0.3, 3));
}
TEST(TProc, cant_create_proc_without_right_rate)
{
	ASSERT_ANY_THROW(TProc st(1, 7, 0.3, 3));
}
TEST(TProc, cant_create_proc_without_right_intens)
{
	ASSERT_ANY_THROW(TProc st(0.6, 7, 1, 3));
}
TEST(TProc, can_run_job)
{
	TProc st(0.6, 7, 0.3, 3);
	ASSERT_NO_THROW(st.RunJob(3));
}
