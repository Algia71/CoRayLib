// VarArgList.h
//

#ifndef _VARARGLIST_H
#define _VARARGLIST_H

#include <stdarg.h>
#include <new>


class VarStrArgList
{
	const size_t m_max_str_args;
	size_t m_pushed_str_args;
	char** m_str_args;

public:
	VarStrArgList(size_t max_str_args)
		: m_max_str_args(max_str_args)
	{
		m_str_args = new(std::nothrow) char* [m_max_str_args]();
		m_pushed_str_args = 0;
	}
	~VarStrArgList()
	{
		if (m_str_args) {
			for (size_t i = 0; i < m_pushed_str_args; ++i) {
				if (m_str_args[i])
					free(m_str_args[i]);
			}
			delete[] m_str_args;
		}
	}
	const char* append(const char* s)
	{
		if (!m_str_args || (m_pushed_str_args >= m_max_str_args))
			return nullptr;

		return m_str_args[m_pushed_str_args++] = _strdup(s);
	}
};

class VarArgList
{
	const size_t m_max_args;
	const size_t m_stack_size;
	size_t m_pushed_args;
	char* m_args;
	char* m_next_arg;
	VarStrArgList m_str_args;

public:
	VarArgList(size_t max_args = 40)
		: m_max_args(max_args),
		  m_stack_size(sizeof(char*) * m_max_args),
		  m_str_args(m_max_args)
	{
		m_pushed_args = 0;
		m_next_arg = m_args = new(std::nothrow) char[m_stack_size]();
	}
	~VarArgList()
	{
		if (m_args)
			delete[] m_args;
	}
	void append(char c) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(char*)m_next_arg) = c;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
	void append(int i) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(int*)m_next_arg) = i;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
	void append(unsigned int i) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(unsigned int*)m_next_arg) = i;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
	void append(long i) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(long*)m_next_arg) = i;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
	void append(unsigned long i) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(unsigned long*)m_next_arg) = i;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
	void append(long long i) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(long long*)m_next_arg) = i;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
	void append(unsigned long long i) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(unsigned long long*)m_next_arg) = i;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
	void append(const char* s) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(char**)m_next_arg) = (char*)m_str_args.append(s);
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}
//	void append(float f) {
//		if (!m_args || (m_pushed_args >= m_max_args))
//			return;
//
//		(*(float*)m_next_arg) = f;
//		m_next_arg += sizeof(void*);
//		++m_pushed_args;
//	}
	void append(double d) {
		if (!m_args || (m_pushed_args >= m_max_args))
			return;

		(*(double*)m_next_arg) = d;
		m_next_arg += sizeof(void*);
		++m_pushed_args;
	}

	va_list get_args()
	{
		return (va_list)m_args;
	}
};

#endif // _VARARGLIST_H
