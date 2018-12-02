#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue <int> st(5));
}
TEST(TQueue, cant_create_too_large_length)
{
	ASSERT_ANY_THROW(TQueue<int>st(MAX_QUEUE_SIZE+1));
}
TEST(TQueue, can_create_queue_with_negativ_length)
{
	ASSERT_ANY_THROW(TQueue<int>st(-1));
}
TEST(TQueue,check_IsEmpty_with_empty_queue)
{
	TQueue<int> st(5);
	EXPECT_TRUE(st.IsEmpty());
}
TEST(TQueue, check_IsEmpty_with_not_empty_queue)
{
	TQueue<int> st(5);
	st.Add(1);
	EXPECT_FALSE(st.IsEmpty());
}
TEST(TQueue, check_IsFull_with_full_queue)
{
	TQueue<int> st(5);
	while(!st.IsFull())
		st.Add(1);
	EXPECT_TRUE(st.IsFull());
}
TEST(TQueue, check_IsFull_with_not_full_queue)
{
	TQueue<int> st(5);
	st.Add(1);
	EXPECT_FALSE(st.IsFull());
}
TEST(TQueue, throws_when_Pop_stack_IsEmty)
{
	TQueue<int> st(5);
	ASSERT_ANY_THROW(st.Pop());
}
TEST(TQueue, throws_when_Push_queue_IsFull)
{
	TQueue<int> st(5);
	while (!st.IsFull())
		st.Add(1);
	ASSERT_ANY_THROW(st.Add(1));
}
TEST(TQueue, can_get_top_element_from_queue)
{
	TQueue<int> st(5);
		st.Add(1);
		EXPECT_EQ(1, st.Pop());
}