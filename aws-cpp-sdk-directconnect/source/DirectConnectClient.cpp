﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/core/utils/Outcome.h>
#include <aws/core/auth/AWSAuthSigner.h>
#include <aws/core/client/CoreErrors.h>
#include <aws/core/client/RetryStrategy.h>
#include <aws/core/http/HttpClient.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/http/HttpClientFactory.h>
#include <aws/core/auth/AWSCredentialsProviderChain.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/threading/Executor.h>
#include <aws/directconnect/DirectConnectClient.h>
#include <aws/directconnect/DirectConnectEndpoint.h>
#include <aws/directconnect/DirectConnectErrorMarshaller.h>
#include <aws/directconnect/model/AllocateConnectionOnInterconnectRequest.h>
#include <aws/directconnect/model/AllocatePrivateVirtualInterfaceRequest.h>
#include <aws/directconnect/model/AllocatePublicVirtualInterfaceRequest.h>
#include <aws/directconnect/model/ConfirmConnectionRequest.h>
#include <aws/directconnect/model/ConfirmPrivateVirtualInterfaceRequest.h>
#include <aws/directconnect/model/ConfirmPublicVirtualInterfaceRequest.h>
#include <aws/directconnect/model/CreateConnectionRequest.h>
#include <aws/directconnect/model/CreateInterconnectRequest.h>
#include <aws/directconnect/model/CreatePrivateVirtualInterfaceRequest.h>
#include <aws/directconnect/model/CreatePublicVirtualInterfaceRequest.h>
#include <aws/directconnect/model/DeleteConnectionRequest.h>
#include <aws/directconnect/model/DeleteInterconnectRequest.h>
#include <aws/directconnect/model/DeleteVirtualInterfaceRequest.h>
#include <aws/directconnect/model/DescribeConnectionLoaRequest.h>
#include <aws/directconnect/model/DescribeConnectionsRequest.h>
#include <aws/directconnect/model/DescribeConnectionsOnInterconnectRequest.h>
#include <aws/directconnect/model/DescribeInterconnectLoaRequest.h>
#include <aws/directconnect/model/DescribeInterconnectsRequest.h>
#include <aws/directconnect/model/DescribeVirtualInterfacesRequest.h>

using namespace Aws;
using namespace Aws::Auth;
using namespace Aws::Client;
using namespace Aws::DirectConnect;
using namespace Aws::DirectConnect::Model;
using namespace Aws::Http;
using namespace Aws::Utils::Json;

static const char* SERVICE_NAME = "directconnect";
static const char* ALLOCATION_TAG = "DirectConnectClient";


DirectConnectClient::DirectConnectClient(const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, Aws::MakeShared<DefaultAWSCredentialsProviderChain>(ALLOCATION_TAG),
        SERVICE_NAME, clientConfiguration.region),
    Aws::MakeShared<DirectConnectErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

DirectConnectClient::DirectConnectClient(const AWSCredentials& credentials, const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, Aws::MakeShared<SimpleAWSCredentialsProvider>(ALLOCATION_TAG, credentials),
         SERVICE_NAME, clientConfiguration.region),
    Aws::MakeShared<DirectConnectErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

DirectConnectClient::DirectConnectClient(const std::shared_ptr<AWSCredentialsProvider>& credentialsProvider,
  const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, credentialsProvider,
         SERVICE_NAME, clientConfiguration.region),
    Aws::MakeShared<DirectConnectErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

DirectConnectClient::~DirectConnectClient()
{
}

void DirectConnectClient::init(const ClientConfiguration& config)
{
  Aws::StringStream ss;
  ss << SchemeMapper::ToString(config.scheme) << "://";

  if(config.endpointOverride.empty())
  {
    ss << DirectConnectEndpoint::ForRegion(config.region, config.useDualStack);
  }
  else
  {
    ss << config.endpointOverride;
  }

  m_uri = ss.str();
}

AllocateConnectionOnInterconnectOutcome DirectConnectClient::AllocateConnectionOnInterconnect(const AllocateConnectionOnInterconnectRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return AllocateConnectionOnInterconnectOutcome(AllocateConnectionOnInterconnectResult(outcome.GetResult()));
  }
  else
  {
    return AllocateConnectionOnInterconnectOutcome(outcome.GetError());
  }
}

AllocateConnectionOnInterconnectOutcomeCallable DirectConnectClient::AllocateConnectionOnInterconnectCallable(const AllocateConnectionOnInterconnectRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->AllocateConnectionOnInterconnect(request); } );
}

void DirectConnectClient::AllocateConnectionOnInterconnectAsync(const AllocateConnectionOnInterconnectRequest& request, const AllocateConnectionOnInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->AllocateConnectionOnInterconnectAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::AllocateConnectionOnInterconnectAsyncHelper(const AllocateConnectionOnInterconnectRequest& request, const AllocateConnectionOnInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, AllocateConnectionOnInterconnect(request), context);
}

AllocatePrivateVirtualInterfaceOutcome DirectConnectClient::AllocatePrivateVirtualInterface(const AllocatePrivateVirtualInterfaceRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return AllocatePrivateVirtualInterfaceOutcome(AllocatePrivateVirtualInterfaceResult(outcome.GetResult()));
  }
  else
  {
    return AllocatePrivateVirtualInterfaceOutcome(outcome.GetError());
  }
}

AllocatePrivateVirtualInterfaceOutcomeCallable DirectConnectClient::AllocatePrivateVirtualInterfaceCallable(const AllocatePrivateVirtualInterfaceRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->AllocatePrivateVirtualInterface(request); } );
}

void DirectConnectClient::AllocatePrivateVirtualInterfaceAsync(const AllocatePrivateVirtualInterfaceRequest& request, const AllocatePrivateVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->AllocatePrivateVirtualInterfaceAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::AllocatePrivateVirtualInterfaceAsyncHelper(const AllocatePrivateVirtualInterfaceRequest& request, const AllocatePrivateVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, AllocatePrivateVirtualInterface(request), context);
}

AllocatePublicVirtualInterfaceOutcome DirectConnectClient::AllocatePublicVirtualInterface(const AllocatePublicVirtualInterfaceRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return AllocatePublicVirtualInterfaceOutcome(AllocatePublicVirtualInterfaceResult(outcome.GetResult()));
  }
  else
  {
    return AllocatePublicVirtualInterfaceOutcome(outcome.GetError());
  }
}

AllocatePublicVirtualInterfaceOutcomeCallable DirectConnectClient::AllocatePublicVirtualInterfaceCallable(const AllocatePublicVirtualInterfaceRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->AllocatePublicVirtualInterface(request); } );
}

void DirectConnectClient::AllocatePublicVirtualInterfaceAsync(const AllocatePublicVirtualInterfaceRequest& request, const AllocatePublicVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->AllocatePublicVirtualInterfaceAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::AllocatePublicVirtualInterfaceAsyncHelper(const AllocatePublicVirtualInterfaceRequest& request, const AllocatePublicVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, AllocatePublicVirtualInterface(request), context);
}

ConfirmConnectionOutcome DirectConnectClient::ConfirmConnection(const ConfirmConnectionRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return ConfirmConnectionOutcome(ConfirmConnectionResult(outcome.GetResult()));
  }
  else
  {
    return ConfirmConnectionOutcome(outcome.GetError());
  }
}

ConfirmConnectionOutcomeCallable DirectConnectClient::ConfirmConnectionCallable(const ConfirmConnectionRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->ConfirmConnection(request); } );
}

void DirectConnectClient::ConfirmConnectionAsync(const ConfirmConnectionRequest& request, const ConfirmConnectionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ConfirmConnectionAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::ConfirmConnectionAsyncHelper(const ConfirmConnectionRequest& request, const ConfirmConnectionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ConfirmConnection(request), context);
}

ConfirmPrivateVirtualInterfaceOutcome DirectConnectClient::ConfirmPrivateVirtualInterface(const ConfirmPrivateVirtualInterfaceRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return ConfirmPrivateVirtualInterfaceOutcome(ConfirmPrivateVirtualInterfaceResult(outcome.GetResult()));
  }
  else
  {
    return ConfirmPrivateVirtualInterfaceOutcome(outcome.GetError());
  }
}

ConfirmPrivateVirtualInterfaceOutcomeCallable DirectConnectClient::ConfirmPrivateVirtualInterfaceCallable(const ConfirmPrivateVirtualInterfaceRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->ConfirmPrivateVirtualInterface(request); } );
}

void DirectConnectClient::ConfirmPrivateVirtualInterfaceAsync(const ConfirmPrivateVirtualInterfaceRequest& request, const ConfirmPrivateVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ConfirmPrivateVirtualInterfaceAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::ConfirmPrivateVirtualInterfaceAsyncHelper(const ConfirmPrivateVirtualInterfaceRequest& request, const ConfirmPrivateVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ConfirmPrivateVirtualInterface(request), context);
}

ConfirmPublicVirtualInterfaceOutcome DirectConnectClient::ConfirmPublicVirtualInterface(const ConfirmPublicVirtualInterfaceRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return ConfirmPublicVirtualInterfaceOutcome(ConfirmPublicVirtualInterfaceResult(outcome.GetResult()));
  }
  else
  {
    return ConfirmPublicVirtualInterfaceOutcome(outcome.GetError());
  }
}

ConfirmPublicVirtualInterfaceOutcomeCallable DirectConnectClient::ConfirmPublicVirtualInterfaceCallable(const ConfirmPublicVirtualInterfaceRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->ConfirmPublicVirtualInterface(request); } );
}

void DirectConnectClient::ConfirmPublicVirtualInterfaceAsync(const ConfirmPublicVirtualInterfaceRequest& request, const ConfirmPublicVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ConfirmPublicVirtualInterfaceAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::ConfirmPublicVirtualInterfaceAsyncHelper(const ConfirmPublicVirtualInterfaceRequest& request, const ConfirmPublicVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ConfirmPublicVirtualInterface(request), context);
}

CreateConnectionOutcome DirectConnectClient::CreateConnection(const CreateConnectionRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return CreateConnectionOutcome(CreateConnectionResult(outcome.GetResult()));
  }
  else
  {
    return CreateConnectionOutcome(outcome.GetError());
  }
}

CreateConnectionOutcomeCallable DirectConnectClient::CreateConnectionCallable(const CreateConnectionRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->CreateConnection(request); } );
}

void DirectConnectClient::CreateConnectionAsync(const CreateConnectionRequest& request, const CreateConnectionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->CreateConnectionAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::CreateConnectionAsyncHelper(const CreateConnectionRequest& request, const CreateConnectionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, CreateConnection(request), context);
}

CreateInterconnectOutcome DirectConnectClient::CreateInterconnect(const CreateInterconnectRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return CreateInterconnectOutcome(CreateInterconnectResult(outcome.GetResult()));
  }
  else
  {
    return CreateInterconnectOutcome(outcome.GetError());
  }
}

CreateInterconnectOutcomeCallable DirectConnectClient::CreateInterconnectCallable(const CreateInterconnectRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->CreateInterconnect(request); } );
}

void DirectConnectClient::CreateInterconnectAsync(const CreateInterconnectRequest& request, const CreateInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->CreateInterconnectAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::CreateInterconnectAsyncHelper(const CreateInterconnectRequest& request, const CreateInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, CreateInterconnect(request), context);
}

CreatePrivateVirtualInterfaceOutcome DirectConnectClient::CreatePrivateVirtualInterface(const CreatePrivateVirtualInterfaceRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return CreatePrivateVirtualInterfaceOutcome(CreatePrivateVirtualInterfaceResult(outcome.GetResult()));
  }
  else
  {
    return CreatePrivateVirtualInterfaceOutcome(outcome.GetError());
  }
}

CreatePrivateVirtualInterfaceOutcomeCallable DirectConnectClient::CreatePrivateVirtualInterfaceCallable(const CreatePrivateVirtualInterfaceRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->CreatePrivateVirtualInterface(request); } );
}

void DirectConnectClient::CreatePrivateVirtualInterfaceAsync(const CreatePrivateVirtualInterfaceRequest& request, const CreatePrivateVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->CreatePrivateVirtualInterfaceAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::CreatePrivateVirtualInterfaceAsyncHelper(const CreatePrivateVirtualInterfaceRequest& request, const CreatePrivateVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, CreatePrivateVirtualInterface(request), context);
}

CreatePublicVirtualInterfaceOutcome DirectConnectClient::CreatePublicVirtualInterface(const CreatePublicVirtualInterfaceRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return CreatePublicVirtualInterfaceOutcome(CreatePublicVirtualInterfaceResult(outcome.GetResult()));
  }
  else
  {
    return CreatePublicVirtualInterfaceOutcome(outcome.GetError());
  }
}

CreatePublicVirtualInterfaceOutcomeCallable DirectConnectClient::CreatePublicVirtualInterfaceCallable(const CreatePublicVirtualInterfaceRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->CreatePublicVirtualInterface(request); } );
}

void DirectConnectClient::CreatePublicVirtualInterfaceAsync(const CreatePublicVirtualInterfaceRequest& request, const CreatePublicVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->CreatePublicVirtualInterfaceAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::CreatePublicVirtualInterfaceAsyncHelper(const CreatePublicVirtualInterfaceRequest& request, const CreatePublicVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, CreatePublicVirtualInterface(request), context);
}

DeleteConnectionOutcome DirectConnectClient::DeleteConnection(const DeleteConnectionRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DeleteConnectionOutcome(DeleteConnectionResult(outcome.GetResult()));
  }
  else
  {
    return DeleteConnectionOutcome(outcome.GetError());
  }
}

DeleteConnectionOutcomeCallable DirectConnectClient::DeleteConnectionCallable(const DeleteConnectionRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DeleteConnection(request); } );
}

void DirectConnectClient::DeleteConnectionAsync(const DeleteConnectionRequest& request, const DeleteConnectionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DeleteConnectionAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DeleteConnectionAsyncHelper(const DeleteConnectionRequest& request, const DeleteConnectionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DeleteConnection(request), context);
}

DeleteInterconnectOutcome DirectConnectClient::DeleteInterconnect(const DeleteInterconnectRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DeleteInterconnectOutcome(DeleteInterconnectResult(outcome.GetResult()));
  }
  else
  {
    return DeleteInterconnectOutcome(outcome.GetError());
  }
}

DeleteInterconnectOutcomeCallable DirectConnectClient::DeleteInterconnectCallable(const DeleteInterconnectRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DeleteInterconnect(request); } );
}

void DirectConnectClient::DeleteInterconnectAsync(const DeleteInterconnectRequest& request, const DeleteInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DeleteInterconnectAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DeleteInterconnectAsyncHelper(const DeleteInterconnectRequest& request, const DeleteInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DeleteInterconnect(request), context);
}

DeleteVirtualInterfaceOutcome DirectConnectClient::DeleteVirtualInterface(const DeleteVirtualInterfaceRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DeleteVirtualInterfaceOutcome(DeleteVirtualInterfaceResult(outcome.GetResult()));
  }
  else
  {
    return DeleteVirtualInterfaceOutcome(outcome.GetError());
  }
}

DeleteVirtualInterfaceOutcomeCallable DirectConnectClient::DeleteVirtualInterfaceCallable(const DeleteVirtualInterfaceRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DeleteVirtualInterface(request); } );
}

void DirectConnectClient::DeleteVirtualInterfaceAsync(const DeleteVirtualInterfaceRequest& request, const DeleteVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DeleteVirtualInterfaceAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DeleteVirtualInterfaceAsyncHelper(const DeleteVirtualInterfaceRequest& request, const DeleteVirtualInterfaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DeleteVirtualInterface(request), context);
}

DescribeConnectionLoaOutcome DirectConnectClient::DescribeConnectionLoa(const DescribeConnectionLoaRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeConnectionLoaOutcome(DescribeConnectionLoaResult(outcome.GetResult()));
  }
  else
  {
    return DescribeConnectionLoaOutcome(outcome.GetError());
  }
}

DescribeConnectionLoaOutcomeCallable DirectConnectClient::DescribeConnectionLoaCallable(const DescribeConnectionLoaRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DescribeConnectionLoa(request); } );
}

void DirectConnectClient::DescribeConnectionLoaAsync(const DescribeConnectionLoaRequest& request, const DescribeConnectionLoaResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeConnectionLoaAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DescribeConnectionLoaAsyncHelper(const DescribeConnectionLoaRequest& request, const DescribeConnectionLoaResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeConnectionLoa(request), context);
}

DescribeConnectionsOutcome DirectConnectClient::DescribeConnections(const DescribeConnectionsRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeConnectionsOutcome(DescribeConnectionsResult(outcome.GetResult()));
  }
  else
  {
    return DescribeConnectionsOutcome(outcome.GetError());
  }
}

DescribeConnectionsOutcomeCallable DirectConnectClient::DescribeConnectionsCallable(const DescribeConnectionsRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DescribeConnections(request); } );
}

void DirectConnectClient::DescribeConnectionsAsync(const DescribeConnectionsRequest& request, const DescribeConnectionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeConnectionsAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DescribeConnectionsAsyncHelper(const DescribeConnectionsRequest& request, const DescribeConnectionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeConnections(request), context);
}

DescribeConnectionsOnInterconnectOutcome DirectConnectClient::DescribeConnectionsOnInterconnect(const DescribeConnectionsOnInterconnectRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeConnectionsOnInterconnectOutcome(DescribeConnectionsOnInterconnectResult(outcome.GetResult()));
  }
  else
  {
    return DescribeConnectionsOnInterconnectOutcome(outcome.GetError());
  }
}

DescribeConnectionsOnInterconnectOutcomeCallable DirectConnectClient::DescribeConnectionsOnInterconnectCallable(const DescribeConnectionsOnInterconnectRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DescribeConnectionsOnInterconnect(request); } );
}

void DirectConnectClient::DescribeConnectionsOnInterconnectAsync(const DescribeConnectionsOnInterconnectRequest& request, const DescribeConnectionsOnInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeConnectionsOnInterconnectAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DescribeConnectionsOnInterconnectAsyncHelper(const DescribeConnectionsOnInterconnectRequest& request, const DescribeConnectionsOnInterconnectResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeConnectionsOnInterconnect(request), context);
}

DescribeInterconnectLoaOutcome DirectConnectClient::DescribeInterconnectLoa(const DescribeInterconnectLoaRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeInterconnectLoaOutcome(DescribeInterconnectLoaResult(outcome.GetResult()));
  }
  else
  {
    return DescribeInterconnectLoaOutcome(outcome.GetError());
  }
}

DescribeInterconnectLoaOutcomeCallable DirectConnectClient::DescribeInterconnectLoaCallable(const DescribeInterconnectLoaRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DescribeInterconnectLoa(request); } );
}

void DirectConnectClient::DescribeInterconnectLoaAsync(const DescribeInterconnectLoaRequest& request, const DescribeInterconnectLoaResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeInterconnectLoaAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DescribeInterconnectLoaAsyncHelper(const DescribeInterconnectLoaRequest& request, const DescribeInterconnectLoaResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeInterconnectLoa(request), context);
}

DescribeInterconnectsOutcome DirectConnectClient::DescribeInterconnects(const DescribeInterconnectsRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeInterconnectsOutcome(DescribeInterconnectsResult(outcome.GetResult()));
  }
  else
  {
    return DescribeInterconnectsOutcome(outcome.GetError());
  }
}

DescribeInterconnectsOutcomeCallable DirectConnectClient::DescribeInterconnectsCallable(const DescribeInterconnectsRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DescribeInterconnects(request); } );
}

void DirectConnectClient::DescribeInterconnectsAsync(const DescribeInterconnectsRequest& request, const DescribeInterconnectsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeInterconnectsAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DescribeInterconnectsAsyncHelper(const DescribeInterconnectsRequest& request, const DescribeInterconnectsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeInterconnects(request), context);
}

DescribeLocationsOutcome DirectConnectClient::DescribeLocations() const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeLocationsOutcome(DescribeLocationsResult(outcome.GetResult()));
  }
  else
  {
    return DescribeLocationsOutcome(outcome.GetError());
  }
}

DescribeLocationsOutcomeCallable DirectConnectClient::DescribeLocationsCallable() const
{
  return std::async(std::launch::async, [this](){ return this->DescribeLocations(); } );
}

void DirectConnectClient::DescribeLocationsAsync(const DescribeLocationsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, handler, context](){ this->DescribeLocationsAsyncHelper( handler, context ); } );
}

void DirectConnectClient::DescribeLocationsAsyncHelper(const DescribeLocationsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, DescribeLocations(), context);
}

DescribeVirtualGatewaysOutcome DirectConnectClient::DescribeVirtualGateways() const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeVirtualGatewaysOutcome(DescribeVirtualGatewaysResult(outcome.GetResult()));
  }
  else
  {
    return DescribeVirtualGatewaysOutcome(outcome.GetError());
  }
}

DescribeVirtualGatewaysOutcomeCallable DirectConnectClient::DescribeVirtualGatewaysCallable() const
{
  return std::async(std::launch::async, [this](){ return this->DescribeVirtualGateways(); } );
}

void DirectConnectClient::DescribeVirtualGatewaysAsync(const DescribeVirtualGatewaysResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, handler, context](){ this->DescribeVirtualGatewaysAsyncHelper( handler, context ); } );
}

void DirectConnectClient::DescribeVirtualGatewaysAsyncHelper(const DescribeVirtualGatewaysResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, DescribeVirtualGateways(), context);
}

DescribeVirtualInterfacesOutcome DirectConnectClient::DescribeVirtualInterfaces(const DescribeVirtualInterfacesRequest& request) const
{
  Aws::StringStream ss;
  ss << m_uri << "/";

  JsonOutcome outcome = MakeRequest(ss.str(), request, HttpMethod::HTTP_POST);
  if(outcome.IsSuccess())
  {
    return DescribeVirtualInterfacesOutcome(DescribeVirtualInterfacesResult(outcome.GetResult()));
  }
  else
  {
    return DescribeVirtualInterfacesOutcome(outcome.GetError());
  }
}

DescribeVirtualInterfacesOutcomeCallable DirectConnectClient::DescribeVirtualInterfacesCallable(const DescribeVirtualInterfacesRequest& request) const
{
  return std::async(std::launch::async, [this, request](){ return this->DescribeVirtualInterfaces(request); } );
}

void DirectConnectClient::DescribeVirtualInterfacesAsync(const DescribeVirtualInterfacesRequest& request, const DescribeVirtualInterfacesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeVirtualInterfacesAsyncHelper( request, handler, context ); } );
}

void DirectConnectClient::DescribeVirtualInterfacesAsyncHelper(const DescribeVirtualInterfacesRequest& request, const DescribeVirtualInterfacesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeVirtualInterfaces(request), context);
}

