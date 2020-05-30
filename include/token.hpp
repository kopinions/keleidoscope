#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <memory>
#include <iostream>
#include <string>

class value {
public:
  value(std::string v) : _v(std::move(v)) {}
  std::string string() { return _v; };

private:
  std::string _v;
};
class token {
public:
  enum type {
    eof = -1,
    def = -2,
    ext = -3,
    identifier = -4,
    number = -5,
    singular = -6
  };
  token(type t, value val) : _type(t), _val(std::make_unique<value>(val)) {}
  std::unique_ptr<value> val() { return std::move(_val); }
  enum type type() { return _type; }

private:
  enum type _type;
  std::unique_ptr<value> _val;
};

#endif // TOKEN_HPP
