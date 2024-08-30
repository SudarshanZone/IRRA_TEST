
------------------------------------------------------Open_Pos Service----------------------------------------------
# Project Documentation for the `Open_Pos` Service

# 1. Introduction

The `Open_Pos` service is That Display Futures and Option Ope Positions 

# 2. Purpose

The `Open_Pos` service aims to:

- Provide a reliable interface for querying financial positions.
- Ensure efficient data retrieval from the PostgreSQL database.
- Serve position data via gRPC, allowing for scalable and performant interactions with clients.

# 3. Architecture Overview

The `Open_Pos` service follows a modular architecture consisting of several key components:

1. Configuration Management
2. Data Access Layer (Repository)
3. Business Logic Layer (Service)
4. gRPC Server Setup

# 4. Components

4.1 Configuration Management

- Purpose: Handles the loading and management of configuration settings required for the service's operation. This includes database connection details.
- Functionality:
    - Loads database configuration from external files (e.g., INI files).
    - Establishes and manages connections to the PostgreSQL database.
    - Provides access to the database connection for other components.

4.2 Data Access Layer (Repository)

- Purpose: Interacts directly with the PostgreSQL database to perform CRUD operations and query data.
- Functionality:
    - Contains methods to query the database and fetch financial positions based on specified criteria.
    - Ensures that data retrieval is performed efficiently and correctly.

4.3 Business Logic Layer (Service)

- Purpose: Implements the core business logic of the service. This layer acts as the intermediary between the gRPC server and the data access layer.
- Functionality:
    - Contains service methods that handle incoming gRPC requests.
    - Processes data received from the repository and formats it for response.
    - Encapsulates business rules and logic related to financial positions.

4.4 gRPC Server Setup

- Purpose: Sets up and runs the gRPC server to handle incoming client requests.
- Functionality:
    - Initializes the gRPC server and registers service implementations.
    - Listens for incoming connections on a specified port.
    - Routes requests to the appropriate service methods and returns responses to clients.

# 5. Operational Flow

1. Initialization:
    - The service starts by loading configuration settings.
    - Establishes a connection to the PostgreSQL database.
2. gRPC Server Setup:
    - Initializes the gRPC server and binds it to a network port.
    - Registers service implementations that define how requests are handled.
3. Request Handling:
    - When a gRPC request is received, the server routes it to the appropriate service method.
    - The service method interacts with the repository to fetch data from the database.
    - The retrieved data is processed and formatted for response.
4. Response Delivery:
    - The service returns the formatted data to the gRPC server.
    - The server sends the response back to the client.

# 6. Configuration Details

- Database Configuration:
    - The service uses PostgreSQL as its database. Configuration details such as host, port, username, password, and database name are specified in an external INI file.
    - Ensure that the database is accessible and the configuration is correctly set to avoid connection issues.
- gRPC Configuration:
    - The gRPC server is configured to listen on a specific port . Ensure that this port is open and not in use by other services.

# 7. Deployment and Testing

- Deployment:
    - Build the service executable and deploy it to the desired environment.
    - Ensure that the PostgreSQL database and gRPC server are correctly configured.
- Testing:
    - Use gRPC client tools to test the service endpoints and verify that the service responds correctly to requests.
    - Perform end-to-end testing to ensure that the integration between the service, database, and gRPC server is functioning as expected.


## 8. Project Structure

The project is organized following a Hexagonal Architecture (also known as Ports and Adapters). The structure is modular and ensures separation of concerns. Here’s an overview of the project structure:

```
Open_Pos/
│
├── cmd/
│   └── main.go                  # Entry point of the application
│
├── config/
|   |── EnvConfig.ini            # Servers Ports and Database Credentials
│   └── config.go                # Configuration management for PostgreSQL
│
├── internal/
│   ├── models/                  # Data models used by the repository and service
│   ├── repository/              # Data access layer
│   │   └── fno_position_repository.go
│   └── service/                # Business logic layer
│       └── fno_position_service.go
│
├── generated/                   # gRPC generated code
│   ├── fno_pos.pb.go            # gRPC message and service definitions
│   └── fno_pos_grpc.pb.go       # gRPC service client and server definitions
│
└── proto/
    └── fno_pos.proto            # Protocol buffer definitions
```

## 9. Architecture Overview

4.1 Hexagonal Architecture

The Hexagonal Architecture divides the application into several layers, each with distinct responsibilities:

1. Core Domain (Business Logic):
   - Service Layer: Implements the core business logic and interacts with the repository.
   
2. Adapters:
   - Repository (Data Access): Manages interactions with the PostgreSQL database.
   - Configuration: Handles loading and managing configuration settings.
   - gRPC Server: Exposes the service functionality over gRPC.

3. Ports:
   - gRPC Service Interface: Defines the communication protocol for interacting with the service.

## 5. Proto Definition and gRPC Integration

5.1 Proto Definition

The `.proto` file defines the data structures and service interfaces for gRPC communication.


5.2 gRPC Integration

- gRPC Server Initialization: The server is set up to listen on a specific port (e.g., `50051`). It registers the service implementation (i.e., `FnoPositionService`) to handle incoming gRPC requests.
- Service Implementation: The service methods handle requests by interacting with the repository to fetch data and then format it for the response.
- Client Communication: Clients communicate with the service using gRPC, sending requests and receiving responses based on the defined service methods.

## 6. How to Run the Service

6.1 Prerequisites

- Go Installation: Ensure that Go is installed on your machine.
- PostgreSQL Database: Ensure that a PostgreSQL database is set up and accessible.

6.2 Steps to Run

1. Build the Service:
   - Navigate to the project root directory.
   - Run `go build -o open_pos ./cmd` to build the service executable.

2. Configure the Database:
   - Create a configuration file (e.g., `config/EnvConfig.ini`) with PostgreSQL connection details.

3. Start the Service:
   - Run the executable: `./open_pos`.
   - The service will start listening on the configured port (e.g., `50051`).

4. Test the Service:
   - Use a gRPC client (e.g., `grpcurl`, Postman) to send requests to the service and verify that it responds correctly.



------------------------------------------------------Open_Pos_Service----------------------------------------------


------------------------------------------------------Ord_Dtls_Service----------------------------------------------
### Project Documentation for `Ord_Stls_Service`

#### 1. **Introduction**

The `Ord_Stls_Service` is a microservice designed to manage order status data using gRPC and PostgreSQL.
#### 2. **Purpose**

The `Ord_Stls_Service` aims to:
- Provide a reliable gRPC interface for querying order status details.
- Efficiently retrieve and process data from a PostgreSQL database.
- Serve order status information to clients in a structured format.

#### 3. **Architecture Overview**

The `Ord_Stls_Service` follows a **Hexagonal Architecture** (also known as Ports and Adapters Architecture), which focuses on separating the core business logic from external concerns such as database access and gRPC communication. This design allows the service to be more modular, testable, and adaptable to changes.

#### 4. **Project Structure**

The project is organized into several key packages, each representing a distinct layer of the Hexagonal Architecture:

1. **`cmd`**: Contains the main entry point for the application.
   - **`main.go`**: Initializes and starts the gRPC server.

2. **`config`**: Manages configuration loading and database connection setup.
   - **`config.go`**: Defines the `ConfigManager` responsible for loading configuration and managing database connections.

3. **`repository`**: Contains data access logic and interacts with the PostgreSQL database.
   - **`repository.go`**: Defines the `OrderDetailsRepository` with methods for querying order details from the database.

4. **`service`**: Implements the core business logic and interacts with the gRPC server.
   - **`service.go`**: Defines the `OrderDetailsService`, which handles gRPC requests and uses the repository to fetch and process data.

5. **`generated`**: Contains auto-generated code from Protocol Buffers definitions.
   - **`order_details.pb.go`**: Generated by `protoc`, defines the gRPC service and message types.

6. **`internal/models`**: Defines data models and structures used within the repository and service layers.
   - **`models.go`**: Includes data models and utility functions for database interaction.

7. **`common`**: Provides common utilities and types used across the project.
   - **`common.go`**: Defines shared configuration types and constants.

#### 5. **How gRPC Works in This Service**

**5.1 gRPC Basics**

gRPC (gRPC Remote Procedure Calls) is a framework that enables communication between client and server applications through defined service methods and message types. It uses Protocol Buffers (protobuf) for defining service interfaces and serializing messages.

**5.2 gRPC in `Ord_Stls_Service`**

1. **Service Definition:**
   - The `OrderDetailsService` implements the gRPC service defined in `order_details.proto`. This service includes the `GetOrderDetails` method, which clients can call to request order details based on a claim match account.

2. **gRPC Server Setup:**
   - In `main.go`, a gRPC server is initialized and the `OrderDetailsService` is registered with it using `pb.RegisterOrderDetailsServiceServer()`.
   - The server listens on a specific TCP port (e.g., `50052`) for incoming client requests.

3. **Request Handling:**
   - When a client sends a request to the gRPC server, the server routes the request to the appropriate method in `OrderDetailsService`.
   - The `OrderDetailsService` uses the `OrderDetailsRepository` to query the PostgreSQL database and retrieve order details.

4. **Response Formation:**
   - The service method processes the data fetched from the repository and formats it into a response message defined in the protobuf file.
   - The formatted response is sent back to the client through the gRPC server.

5. **Communication Protocol:**
   - gRPC uses HTTP/2 as the transport protocol, which supports multiplexing, flow control, and efficient communication.
   - Messages are serialized using Protocol Buffers, which are compact and efficient for data exchange.

**5.3 Protocol Buffers Definition**

- **`order_details.proto`:** Defines the service and message types. It specifies the `OrderDetailsService` with methods like `GetOrderDetails` and message types like `OrderDetailsRequest` and `OrderDetailsResponse`.
- The `.proto` file is compiled using `protoc` to generate Go code, which includes service interfaces and message types used in the implementation.

#### 6. **Operational Flow**

1. **Initialization:**
   - The service starts by loading configuration settings from the specified INI file.
   - Establishes a connection to the PostgreSQL database using the provided configuration.

2. **gRPC Server Setup:**
   - Sets up the gRPC server, registers the `OrderDetailsService`, and binds it to a specified port (e.g., `50052`).

3. **Request Handling:**
   - Listens for incoming gRPC requests, routes them to the appropriate service method.
   - The service method interacts with the repository to fetch data from the database.

4. **Response Delivery:**
   - Formats the response data and sends it back to the client.

#### 7. **Configuration Details**

- **Database Configuration:**
  - The service uses PostgreSQL. Configuration details are specified in an external INI file.
  - Ensure that the database is accessible and the connection details are accurate to avoid connection issues.

- **gRPC Configuration:**
  - The gRPC server listens on port `50052`. Ensure that this port is open and not used by other services.
