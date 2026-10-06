# Calculator

A small C++ command-line calculator that adds two integers.

Start Docker, then run these commands from this folder:

```sh
BUILDX_GIT_INFO=false BUILDX_GIT_LABELS=false docker build -t tiden-calc .
docker run --rm tiden-calc add 8 3
```

Expected output:

```text
11
```

The compiler is included in the Docker image. A compiler installation on the host is not required. Run the build command again after changing `main.cpp`.

The build variables disable Docker's automatic collection of repository metadata. `.dockerignore` limits the build inputs to the Dockerfile and C++ source.

The command accepts exactly `add` and two decimal integers between -2147483648 and 2147483647. A leading minus sign is supported; a leading plus sign, whitespace, fractions, and trailing characters are rejected. The sum is printed as a 64-bit integer followed by a newline, with exit status 0.

An unsupported operation or wrong argument count prints usage to standard error and exits with status 1. Invalid integers print an error to standard error and exit with status 1. Errors produce no result on standard output.

For example:

```sh
docker run --rm tiden-calc add -8 3
```

Expected output: `-5`.
