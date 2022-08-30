# Pargser

## Usage

"<argument_name>%<argument_type>...;"

"..." is an optional argument that takes unspecified amount of parameter as the last type that is specified until it founds another argument that matches with 
any argument name that is given. (Not implemented)

Additionally, there can be multiple parameters for given argument. ex: "--coordinate%d%d;"

## Argument Types

- b -> boolean
- i -> int
- s -> const char* (direct reference to the argv)
- d -> double
