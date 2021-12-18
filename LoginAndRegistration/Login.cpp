#include "Login.h"
#include <cassert>
#include "leveldb/db.h"

void Login::setUsername(std::string username)
{
	Login::username = username;
}

void Login::setPassword(std::string password)
{
	Login::password = password;
}

bool Login::run()
{
	bool res = false;

	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	const leveldb::Status status = leveldb::DB::Open(options, "usersDatas", &db);
	assert(status.ok());

	std::string value;
	leveldb::Status s = db->Get(leveldb::ReadOptions(), Login::username, &value);
	if (s.ok() && value == Login::password)
	{
		res = true;
	}

	delete db;

	return res;

}