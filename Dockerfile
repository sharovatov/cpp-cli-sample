FROM gcc:15.3.0
WORKDIR /app
COPY main.cpp .
RUN g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o calc
ENTRYPOINT ["/app/calc"]
