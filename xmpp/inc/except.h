/*
 * except.h
 *
 *  Created on: Aug 11, 2012
 *      Author: gambhire
 */

#ifndef EXCEPT_H_
#define EXCEPT_H_

namespace xmpp {

	enum TcpStatus {
		OK = 0,
		ConnRefused,
		ConnClosed,
		ConnReset
	};

	enum TlsStatus {
			OK = 0,
	};

	enum SaslStatus {
		OK = 0
	};

	enum BindStatus {
		OK = 0
	};

	enum XmppStatus {
		OK = 0
	};
	};
}


#endif /* EXCEPT_H_ */
