# Pargser

## Usage

"<argument_name>%<argument_type><...>;"

"..." is an optional argument that takes unspecified amount of parameter as the last type that is specified until founds another argument that matches with 
any argument name that is given. (Not implemented)

Additionally, there can be multiple parameters for given argument. ex: "--coordinate%f%f;"

## Argument Types

- b -> boolean
- i -> int
- s -> const char* (direct reference to the argv)
- d -> double