#ifndef _H_ROCK_DELEGATE
#define _H_ROCK_DELEGATE

#include "Rock_Types.h"
#include "Rock_Defines.h"

namespace Rock {

	template <typename A0>
	class ROCK_API _BaseDelegate {
	public:
		virtual ~_BaseDelegate() {}
		virtual void operator()(void *, A0) =0;
		virtual RBOOL operator==(_BaseDelegate<A0> const& obj) =0;
		virtual RBOOL operator!=(_BaseDelegate<A0> const& obj) =0;

	protected:
		_BaseDelegate() {}
	};

	template <typename A0>
	class ROCK_API Delegate {
	public:
		Delegate(Delegate<A0> const& obj) : m_pDelegate(obj.m_pDelegate), m_pnCount(obj.m_pnCount) {
			++(*m_pnCount);
		}
		Delegate(_BaseDelegate<A0> * pDelegate) : m_pDelegate(pDelegate), m_pnCount(NULL) {
			m_pnCount = new Rock::UInt32(1);
		}
		~Delegate() {
			--(*m_pnCount);
			if(*m_pnCount == 0) {
				delete m_pDelegate;
				delete m_pnCount;
			}
		}
		Delegate<A0>& operator=(Delegate<A0> const& obj) {
			if(m_pnCount != obj.m_pnCount) {
				m_pDelegate = obj.m_pDelegate;
				--(*m_pnCount);
				if(*m_pnCount == 0) {
					delete m_pDelegate;
					delete m_pnCount;
				}
				m_pnCount = obj.m_pnCount;
				++(*m_pnCount);
			}
			return *this;
		}
		void operator()(void* pSender) {
			m_pDelegate->operator()(pSender, a0);
		}
		void operator()(void* pSender, A0 a0) {
			m_pDelegate->operator()(pSender, a0);
		}
		RBOOL operator==(Delegate<A0> const& obj) {
			return m_pDelegate->operator==(*obj.m_pDelegate);
		}
		RBOOL operator!=(Delegate<A0> const& obj) {
			return m_pDelegate->operator!=(*obj.m_pDelegate);
		}

		template <typename T>
		static Delegate<A0> Method(T* pClass, void(T::*pMethod)(void*, A0)) {
			return Delegate<A0>(new _MethodDelegate<T, A0>(pClass, pMethod));
		}
		static Delegate<A0> Function(void(*pFunction)(void*, A0)) {
			return Delegate<A0>(new _FunctionDelegate<A0>(pFunction));
		}

	private:
		_BaseDelegate<A0>* m_pDelegate;
		RUINT32* m_pnCount;
	};

	template <typename T, typename A0>
	class ROCK_API _MethodDelegate : public _BaseDelegate<A0> {
	public:
		typedef T* Class;
		typedef void (T::*Method)(void*, A0);

		_MethodDelegate(Class pClass, Method pMethod) : m_pClass(pClass), m_pMethod(pMethod) {
		}
		void operator()(void *pSender, A0 a0) {
			(*m_pClass.*m_pMethod)(pSender, a0);
		}
		virtual RBOOL operator==(_BaseDelegate<A0> const& obj) {
			return m_pClass == dynamic_cast<_MethodDelegate<T, A0> const&>(obj).m_pClass && m_pMethod == dynamic_cast<_MethodDelegate<T, A0> const&>(obj).m_pMethod;
		}
		virtual RBOOL operator!=(_BaseDelegate<A0> const& obj) {
			return m_pClass != dynamic_cast<_MethodDelegate<T, A0> const&>(obj).m_pClass || m_pMethod != dynamic_cast<_MethodDelegate<T, A0> const&>(obj).m_pMethod;
		}

	private:
		Class m_pClass;
		Method m_pMethod;
	};

	template <typename A0>
	class ROCK_API _FunctionDelegate : public _BaseDelegate<A0> {
	public:
		typedef void (*Function)(void*, A0);

		_FunctionDelegate(Function pFunction) : m_pFunction(pFunction) {
		}
		void operator()(void *pSender, A0 a0) {
			m_pFunction(pSender, a0);
		}
		virtual RBOOL operator==(_BaseDelegate<A0> const& obj) {
			return m_pFunction == dynamic_cast<_FunctionDelegate<A0> const&>(obj).m_pFunction;
		}
		virtual RBOOL operator!=(_BaseDelegate<A0> const& obj) {
			return m_pFunction != dynamic_cast<_FunctionDelegate<A0> const&>(obj).m_pFunction;
		}

	private:
		Function m_pFunction;
	};

};

#endif
