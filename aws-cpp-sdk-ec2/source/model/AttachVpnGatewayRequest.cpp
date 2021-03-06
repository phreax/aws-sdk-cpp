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
#include <aws/ec2/model/AttachVpnGatewayRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

AttachVpnGatewayRequest::AttachVpnGatewayRequest() : 
    m_dryRun(false),
    m_dryRunHasBeenSet(false),
    m_vpnGatewayIdHasBeenSet(false),
    m_vpcIdHasBeenSet(false)
{
}

Aws::String AttachVpnGatewayRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=AttachVpnGateway&";
  if(m_dryRunHasBeenSet)
  {
    ss << "DryRun=" << m_dryRun << "&";
  }

  if(m_vpnGatewayIdHasBeenSet)
  {
    ss << "VpnGatewayId=" << StringUtils::URLEncode(m_vpnGatewayId.c_str()) << "&";
  }

  if(m_vpcIdHasBeenSet)
  {
    ss << "VpcId=" << StringUtils::URLEncode(m_vpcId.c_str()) << "&";
  }

  ss << "Version=2015-10-01";
  return ss.str();
}

