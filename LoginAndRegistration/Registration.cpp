#include "Registration.h"
#include <leveldb/db.h>
#include <termcolor/termcolor.hpp>

void Registration::setUsername(std::string &username)
{
	Registration::username = username;
}

void Registration::setPassword(std::string &password)
{
	Registration::password = password;
}

bool Registration::run()
{
	bool res = false;

	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	const leveldb::Status status = leveldb::DB::Open(options, "usersDatas", &db);
	assert(status.ok());

	leveldb::Status s = db->Put(leveldb::WriteOptions(), Registration::username, Registration::password);
	if (s.ok())
	{
		res = true;
	}

	delete db;

	return res;
}


