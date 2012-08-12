/*
 * connimpl.h
 *
 *  Created on: Aug 12, 2012
 *      Author: gambhire
 */

#ifndef CONNIMPL_H_
#define CONNIMPL_H_

#include "connection.h"

namespace xmpp {

	class ConnectionImpl {
	public:
		ConnectionImpl(const std::string& hostName, const std::string& userName,
					const std::string& password, const std::string& bindJid);
		~ConnectionImpl();

		void registerStatusListener(std::auto_ptr<IStatusListener> listener);
		void registerDataListener(std::auto_ptr<IDataListener> listener);

		void connect() throw (std::bad_alloc);
		void disconnect();

		void sendMsg(const std::string& msgStanza);
		void sendIq(const std::string& iqStanza);

	private:
		const std::string hostName;
		const std::string userName;
		const std::string password;
		const std::string bindJid;

		std::auto_ptr<IStatusListener> statusListener;

	};
}


#endif /* CONNIMPL_H_ */
