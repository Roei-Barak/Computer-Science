#include"QueueStack.h"
#include"StackList.h"
QueueStack::QueueStack() 
{
	data = new StackList;
}
void QueueStack::clear()
{
	data->clear();
}

int QueueStack::dequeue()
{
	StackList temp ;
	int result= 0;
	int tmp;

	while (!data->isEmpty())
	{
		result = data->pop();
		temp.push(result);
	}
	temp.pop();
	while (!temp.isEmpty())
	{
		tmp = temp.pop();
		data->push(tmp);
	}
	return result;
}

void QueueStack::enqueue(int value)
{
	data->push(value);
}

int QueueStack::front()
{
	StackList temp;
	int result = 0;
	int tmp;

	while (!data->isEmpty())
	{
		result = data->pop();
		temp.push(result);
	}
	while (!temp.isEmpty())
	{
		tmp = temp.pop();
		data->push(tmp);
	}
	return result;
}

bool QueueStack::isEmpty() const
{
	return data->isEmpty();
}

