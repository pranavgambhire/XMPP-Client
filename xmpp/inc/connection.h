/*
 * connection.h
 *
 *  Created on: Aug 11, 2012
 *      Author: gambhire
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>
#include <memory>
#include <stdexcept>

#include "except.h"

namespace xmpp {

	class IStatusListener {
	public:
		virtual ~IStatusListener() {}

		//
		// Connection progress status notifications
		//
		virtual void onTcpConnect() = 0;
		virtual void onTlsConnect() = 0;
		virtual void onSaslAuth() = 0;
		virtual void onZipEnable() = 0;
		virtual void onResourceBound() = 0;
		virtual void onEstablish() = 0;

		//
		// Connection error notifications
		//
		virtual void tcpConnectError(const TcpStatus ) = 0;
		virtual void tlsConnectError(const TlsStatus ) = 0;
		virtual void saslAuthError(const SaslStatus ) = 0;
		virtual void bindError(const BindStatus ) = 0;
		virtual void xmppError(const XmppStatus ) = 0;

	};

	class IDataListener {
	public:
		virtual ~IDataListener() {}

		virtual void msgReceived(const std::string& msgStanza) = 0;
		virtual void iqReceived(const std::string& iqStanza) = 0;

	};

	class ConnectionImpl;

	class Connection {
	public:
		Connection(const std::string& hostName, const std::string& userName,
					const std::string& password, const std::string& bindJid);
		~Connection();

		void registerStatusListener(std::auto_ptr<IStatusListener> listener);
		void registerDataListener(std::auto_ptr<IDataListener> listener);

		void connect() throw (std::bad_alloc);
		void disconnect();

		void sendMsg(const std::string& msgStanza);
		void sendIq(const std::string& iqStanza);

	private:
		ConnectionImpl *impl;
	};
}



#endif /* CONNECTION_H_ */
