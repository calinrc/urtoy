/*
 *    file written and maintained by Calin Cocan
 *    Created on: Feb 17, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
 *
 ********************************************************************************************************************* */

#ifndef INITINFO_H_
#define INITINFO_H_

class InitInfo {
public:
	InitInfo(int port) {
		m_port = port;
	}

	InitInfo(InitInfo& otherInfo) {
		m_port = otherInfo.m_port;
	}

	int getPort() {
		return m_port;
	}

private:
	int m_port;
};

class LoginInfo {

public:
	LoginInfo(const char* username, const char* password) {
		m_username = username;
		m_password = password;
	}

	LoginInfo(LoginInfo& otherInfo) {
		m_username = otherInfo.m_username;
		m_password = otherInfo.m_password;
	}

	const char* getUserName() {
		return m_username;
	}

	const char* getPassword() {
		return m_password;
	}

private:
	const char* m_username;
	const char* m_password;

};

#endif /* INITINFO_H_ */
