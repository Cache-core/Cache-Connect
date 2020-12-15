#ifndef ICRYPTENGINE_H
#define ICRYPTENGINE_H

#include <QObject>

namespace CacheConnect
{

/**
 * Cryptography Engine for encrypting and decrypting data
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class ICryptEngine : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief provides RSA public key
	 * @return pulic key
	 */
	virtual QByteArray publicKey() = 0;

	/**
	 * @brief provides RSA private key
	 * @return private key
	 */
	virtual QByteArray privateKey() = 0;

	/**
	 * @brief generates a random password of length 32
	 * @return password generated
	 */
	virtual QByteArray randomPassword() = 0;

	/**
	 * @brief encrypts data provided with RSA 2048 bit encryption
	 * @param[in] pubKey key to encrypt with
	 * @param[in] input data to be encrypted
	 * @param[out] output encrypted data
	 * @return true if data is encrypted without error, false otherwise
	 */
	virtual bool encryptRSA(QByteArray& pubKey, QByteArray& input, QByteArray& output) = 0;

	/**
	 * @brief decrypts a RSA 2048 bit encrypted data
	 * @param[in] input data to be decrypted
	 * @param[out] output decrypted data
	 * @return
	 */
	virtual bool decryptRSA(QByteArray& input, QByteArray& output) = 0;

	/**
	 * @brief encrypts data provided with AES 256 bit encryption
	 * @param pass passphrase to encrypt with
	 * @param[in] input data to be encrypted
	 * @param[out] output encrypted data
	 * @return true if data is encrypted without error, false otherwise
	 */
	virtual bool encryptAES(QByteArray pass, QByteArray& input, QByteArray& output) = 0;

	/**
	 * @brief decrypts a AES 256 bit encrypted data
	 * @param pass passphrase to decrypt with
	 * @param[in] input data to be decrypted
	 * @param[out] output decrypted data
	 * @return true if data is decrypted without error, false otherwise
	 */
	virtual bool decryptAES(QByteArray pass, QByteArray& input, QByteArray& output) = 0;

protected:
	/**
	 * @brief Constructor
	 */
	explicit ICryptEngine(QObject* parent = nullptr);

	/**
	 * @brief Destructor
	 */
	~ICryptEngine();
};

}

#endif
