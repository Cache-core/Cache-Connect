#ifndef RSAPAIR_H
#define RSAPAIR_H

#include <QObject>

namespace CacheConnect
{

/**
 * @brief Generates a pair of RSA 2048 bit keys
 * generate public and private keys using openssl command line
 */
class RSAPair
{
public:
	explicit RSAPair();
	~RSAPair();

	/**
	 * @brief generates a new key pair
	 */
	void generateNewPair();

	/**
	 * @brief public key generated
	 * @return public key
	 */
	QByteArray publicKey();

	/**
	 * @brief private key generated
	 * @return private key
	 */
	QByteArray privateKey();

private:
	QByteArray m_pub;
	QByteArray m_priv;

};

}
#endif
