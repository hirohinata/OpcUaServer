#ifndef status_code_h
#define status_code_h

typedef enum OpcUa_StatusCodeTag
{
    // The operation succeeded.
    Good = 0x00000000,
    // The operation was uncertain.
    Uncertain = 0x40000000,
    // The operation failed.
    Bad = 0x80000000,
    // An unexpected error occurred.
    BadUnexpectedError = 0x80010000,
    // An internal error occurred as a result of a programming or configuration error.
    BadInternalError = 0x80020000,
    // Not enough memory to complete the operation.
    BadOutOfMemory = 0x80030000,
    // An operating system resource is not available.
    BadResourceUnavailable = 0x80040000,
    // A low level communication error occurred.
    BadCommunicationError = 0x80050000,
    // Encoding halted because of invalid data in the objects being serialized.
    BadEncodingError = 0x80060000,
    // Decoding halted because of invalid data in the stream.
    BadDecodingError = 0x80070000,
    // The message encoding/decoding limits imposed by the stack have been exceeded.
    BadEncodingLimitsExceeded = 0x80080000,
    // The request message size exceeds limits set by the server.
    BadRequestTooLarge = 0x80B80000,
    // The response message size exceeds limits set by the client.
    BadResponseTooLarge = 0x80B90000,
    // An unrecognized response was received from the server.
    BadUnknownResponse = 0x80090000,
    // The operation timed out.
    BadTimeout = 0x800A0000,
    // The server does not support the requested service.
    BadServiceUnsupported = 0x800B0000,
    // The operation was cancelled because the application is shutting down.
    BadShutdown = 0x800C0000,
    // The operation could not complete because the client is not connected to the server.
    BadServerNotConnected = 0x800D0000,
    // The server has stopped and cannot process any requests.
    BadServerHalted = 0x800E0000,
    // No processing could be done because there was nothing to do.
    BadNothingToDo = 0x800F0000,
    // The request could not be processed because it specified too many operations.
    BadTooManyOperations = 0x80100000,
    // The request could not be processed because there are too many monitored items in the subscription.
    BadTooManyMonitoredItems = 0x80DB0000,
    // The extension object cannot be (de)serialized because the data type id is not recognized.
    BadDataTypeIdUnknown = 0x80110000,
    // The certificate provided as a parameter is not valid.
    BadCertificateInvalid = 0x80120000,
    // An error occurred verifying security.
    BadSecurityChecksFailed = 0x80130000,
    // The certificate does not meet the requirements of the security policy.
    BadCertificatePolicyCheckFailed = 0x81140000,
    // The certificate has expired or is not yet valid.
    BadCertificateTimeInvalid = 0x80140000,
    // An issuer certificate has expired or is not yet valid.
    BadCertificateIssuerTimeInvalid = 0x80150000,
    // The HostName used to connect to a server does not match a HostName in the certificate.
    BadCertificateHostNameInvalid = 0x80160000,
    // The URI specified in the ApplicationDescription does not match the URI in the certificate.
    BadCertificateUriInvalid = 0x80170000,
    // The certificate may not be used for the requested operation.
    BadCertificateUseNotAllowed = 0x80180000,
    // The issuer certificate may not be used for the requested operation.
    BadCertificateIssuerUseNotAllowed = 0x80190000,
    // The certificate is not trusted.
    BadCertificateUntrusted = 0x801A0000,
    // It was not possible to determine if the certificate has been revoked.
    BadCertificateRevocationUnknown = 0x801B0000,
    // It was not possible to determine if the issuer certificate has been revoked.
    BadCertificateIssuerRevocationUnknown = 0x801C0000,
    // The certificate has been revoked.
    BadCertificateRevoked = 0x801D0000,
    // The issuer certificate has been revoked.
    BadCertificateIssuerRevoked = 0x801E0000,
    // The certificate chain is incomplete.
    BadCertificateChainIncomplete = 0x810D0000,
    // User does not have permission to perform the requested operation.
    BadUserAccessDenied = 0x801F0000,
    // The user identity token is not valid.
    BadIdentityTokenInvalid = 0x80200000,
    // The user identity token is valid but the server has rejected it.
    BadIdentityTokenRejected = 0x80210000,
    // The specified secure channel is no longer valid.
    BadSecureChannelIdInvalid = 0x80220000,
    // The timestamp is outside the range allowed by the server.
    BadInvalidTimestamp = 0x80230000,
    // The nonce does appear to be not a random value or it is not the correct length.
    BadNonceInvalid = 0x80240000,
    // The session id is not valid.
    BadSessionIdInvalid = 0x80250000,
    // The session was closed by the client.
    BadSessionClosed = 0x80260000,
    // The session cannot be used because ActivateSession has not been called.
    BadSessionNotActivated = 0x80270000,
    // The subscription id is not valid.
    BadSubscriptionIdInvalid = 0x80280000,
    // The header for the request is missing or invalid.
    BadRequestHeaderInvalid = 0x802A0000,
    // The timestamps to return parameter is invalid.
    BadTimestampsToReturnInvalid = 0x802B0000,
    // The request was cancelled by the client.
    BadRequestCancelledByClient = 0x802C0000,
    // Too many arguments were provided.
    BadTooManyArguments = 0x80E50000,
    // The server requires a license to operate in general or to perform a service or operation, but existing license is expired.
    BadLicenseExpired = 0x810E0000,
    // The server has limits on number of allowed operations / objects, based on installed licenses, and these limits where exceeded.
    BadLicenseLimitsExceeded = 0x810F0000,
    // The server does not have a license which is required to operate in general or to perform a service or operation.
    BadLicenseNotAvailable = 0x81100000,
    // The subscription was transferred to another session.
    GoodSubscriptionTransferred = 0x002D0000,
    // The processing will complete asynchronously.
    GoodCompletesAsynchronously = 0x002E0000,
    // Sampling has slowed down due to resource limitations.
    GoodOverload = 0x002F0000,
    // The value written was accepted but was clamped.
    GoodClamped = 0x00300000,
    // Communication with the data source is defined, but not established, and there is no last known value available.
    BadNoCommunication = 0x80310000,
    // Waiting for the server to obtain values from the underlying data source.
    BadWaitingForInitialData = 0x80320000,
    // The syntax of the node id is not valid.
    BadNodeIdInvalid = 0x80330000,
    // The node id refers to a node that does not exist in the server address space.
    BadNodeIdUnknown = 0x80340000,
    // The attribute is not supported for the specified Node.
    BadAttributeIdInvalid = 0x80350000,
    // The syntax of the index range parameter is invalid.
    BadIndexRangeInvalid = 0x80360000,
    // No data exists within the range of indexes specified.
    BadIndexRangeNoData = 0x80370000,
    // The data encoding is invalid.
    BadDataEncodingInvalid = 0x80380000,
    // The server does not support the requested data encoding for the node.
    BadDataEncodingUnsupported = 0x80390000,
    // The access level does not allow reading or subscribing to the Node.
    BadNotReadable = 0x803A0000,
    // The access level does not allow writing to the Node.
    BadNotWritable = 0x803B0000,
    // The value was out of range.
    BadOutOfRange = 0x803C0000,
    // The requested operation is not supported.
    BadNotSupported = 0x803D0000,
    // A requested item was not found or a search operation ended without success.
    BadNotFound = 0x803E0000,
    // The object cannot be used because it has been deleted.
    BadObjectDeleted = 0x803F0000,
    // Requested operation is not implemented.
    BadNotImplemented = 0x80400000,
    // The monitoring mode is invalid.
    BadMonitoringModeInvalid = 0x80410000,
    // The monitoring item id does not refer to a valid monitored item.
    BadMonitoredItemIdInvalid = 0x80420000,
    // The monitored item filter parameter is not valid.
    BadMonitoredItemFilterInvalid = 0x80430000,
    // The server does not support the requested monitored item filter.
    BadMonitoredItemFilterUnsupported = 0x80440000,
    // A monitoring filter cannot be used in combination with the attribute specified.
    BadFilterNotAllowed = 0x80450000,
    // A mandatory structured parameter was missing or null.
    BadStructureMissing = 0x80460000,
    // The event filter is not valid.
    BadEventFilterInvalid = 0x80470000,
    // The content filter is not valid.
    BadContentFilterInvalid = 0x80480000,
    // An unrecognized operator was provided in a filter.
    BadFilterOperatorInvalid = 0x80C10000,
    // A valid operator was provided, but the server does not provide support for this filter operator.
    BadFilterOperatorUnsupported = 0x80C20000,
    // The number of operands provided for the filter operator was less then expected for the operand provided.
    BadFilterOperandCountMismatch = 0x80C30000,
    // The operand used in a content filter is not valid.
    BadFilterOperandInvalid = 0x80490000,
    // The referenced element is not a valid element in the content filter.
    BadFilterElementInvalid = 0x80C40000,
    // The referenced literal is not a valid value.
    BadFilterLiteralInvalid = 0x80C50000,
    // The continuation point provide is longer valid.
    BadContinuationPointInvalid = 0x804A0000,
    // The operation could not be processed because all continuation points have been allocated.
    BadNoContinuationPoints = 0x804B0000,
    // The reference type id does not refer to a valid reference type node.
    BadReferenceTypeIdInvalid = 0x804C0000,
    // The browse direction is not valid.
    BadBrowseDirectionInvalid = 0x804D0000,
    // The node is not part of the view.
    BadNodeNotInView = 0x804E0000,
    // The number was not accepted because of a numeric overflow.
    BadNumericOverflow = 0x81120000,
    // The ServerUri is not a valid URI.
    BadServerUriInvalid = 0x804F0000,
    // No ServerName was specified.
    BadServerNameMissing = 0x80500000,
    // No DiscoveryUrl was specified.
    BadDiscoveryUrlMissing = 0x80510000,
    // The semaphore file specified by the client is not valid.
    BadSempahoreFileMissing = 0x80520000,
    // The security token request type is not valid.
    BadRequestTypeInvalid = 0x80530000,
    // The security mode does not meet the requirements set by the server.
    BadSecurityModeRejected = 0x80540000,
    // The security policy does not meet the requirements set by the server.
    BadSecurityPolicyRejected = 0x80550000,
    // The server has reached its maximum number of sessions.
    BadTooManySessions = 0x80560000,
    // The user token signature is missing or invalid.
    BadUserSignatureInvalid = 0x80570000,
    // The signature generated with the client certificate is missing or invalid.
    BadApplicationSignatureInvalid = 0x80580000,
    // The client did not provide at least one software certificate that is valid and meets the profile requirements for the server.
    BadNoValidCertificates = 0x80590000,
    // The server does not support changing the user identity assigned to the session.
    BadIdentityChangeNotSupported = 0x80C60000,
    // The request was cancelled by the client with the Cancel service.
    BadRequestCancelledByRequest = 0x805A0000,
    // The parent node id does not to refer to a valid node.
    BadParentNodeIdInvalid = 0x805B0000,
    // The reference could not be created because it violates constraints imposed by the data model.
    BadReferenceNotAllowed = 0x805C0000,
    // The requested node id was reject because it was either invalid or server does not allow node ids to be specified by the client.
    BadNodeIdRejected = 0x805D0000,
    // The requested node id is already used by another node.
    BadNodeIdExists = 0x805E0000,
    // The node class is not valid.
    BadNodeClassInvalid = 0x805F0000,
    // The browse name is invalid.
    BadBrowseNameInvalid = 0x80600000,
    // The browse name is not unique among nodes that share the same relationship with the parent.
    BadBrowseNameDuplicated = 0x80610000,
    // The node attributes are not valid for the node class.
    BadNodeAttributesInvalid = 0x80620000,
    // The type definition node id does not reference an appropriate type node.
    BadTypeDefinitionInvalid = 0x80630000,
    // The source node id does not reference a valid node.
    BadSourceNodeIdInvalid = 0x80640000,
    // The target node id does not reference a valid node.
    BadTargetNodeIdInvalid = 0x80650000,
    // The reference type between the nodes is already defined.
    BadDuplicateReferenceNotAllowed = 0x80660000,
    // The server does not allow this type of self reference on this node.
    BadInvalidSelfReference = 0x80670000,
    // The reference type is not valid for a reference to a remote server.
    BadReferenceLocalOnly = 0x80680000,
    // The server will not allow the node to be deleted.
    BadNoDeleteRights = 0x80690000,
    // The server was not able to delete all target references.
    UncertainReferenceNotDeleted = 0x40BC0000,
    // The server index is not valid.
    BadServerIndexInvalid = 0x806A0000,
    // The view id does not refer to a valid view node.
    BadViewIdUnknown = 0x806B0000,
    // The view timestamp is not available or not supported.
    BadViewTimestampInvalid = 0x80C90000,
    // The view parameters are not consistent with each other.
    BadViewParameterMismatch = 0x80CA0000,
    // The view version is not available or not supported.
    BadViewVersionInvalid = 0x80CB0000,
    // The list of references may not be complete because the underlying system is not available.
    UncertainNotAllNodesAvailable = 0x40C00000,
    // The server should have followed a reference to a node in a remote server but did not. The result set may be incomplete.
    GoodResultsMayBeIncomplete = 0x00BA0000,
    // The provided Nodeid was not a type definition nodeid.
    BadNotTypeDefinition = 0x80C80000,
    // One of the references to follow in the relative path references to a node in the address space in another server.
    UncertainReferenceOutOfServer = 0x406C0000,
    // The requested operation has too many matches to return.
    BadTooManyMatches = 0x806D0000,
    // The requested operation requires too many resources in the server.
    BadQueryTooComplex = 0x806E0000,
    // The requested operation has no match to return.
    BadNoMatch = 0x806F0000,
    // The max age parameter is invalid.
    BadMaxAgeInvalid = 0x80700000,
    // The operation is not permitted over the current secure channel.
    BadSecurityModeInsufficient = 0x80E60000,
    // The history details parameter is not valid.
    BadHistoryOperationInvalid = 0x80710000,
    // The server does not support the requested operation.
    BadHistoryOperationUnsupported = 0x80720000,
    // The defined timestamp to return was invalid.
    BadInvalidTimestampArgument = 0x80BD0000,
    // The server does not support writing the combination of value, status and timestamps provided.
    BadWriteNotSupported = 0x80730000,
    // The value supplied for the attribute is not of the same type as the attribute's value.
    BadTypeMismatch = 0x80740000,
    // The method id does not refer to a method for the specified object.
    BadMethodInvalid = 0x80750000,
    // The client did not specify all of the input arguments for the method.
    BadArgumentsMissing = 0x80760000,
    // The executable attribute does not allow the execution of the method.
    BadNotExecutable = 0x81110000,
    // The server has reached its maximum number of subscriptions.
    BadTooManySubscriptions = 0x80770000,
    // The server has reached the maximum number of queued publish requests.
    BadTooManyPublishRequests = 0x80780000,
    // There is no subscription available for this session.
    BadNoSubscription = 0x80790000,
    // The sequence number is unknown to the server.
    BadSequenceNumberUnknown = 0x807A0000,
    // The Server does not support retransmission queue and acknowledgement of sequence numbers is not available.
    GoodRetransmissionQueueNotSupported = 0x00DF0000,
    // The requested notification message is no longer available.
    BadMessageNotAvailable = 0x807B0000,
    // The client of the current session does not support one or more Profiles that are necessary for the subscription.
    BadInsufficientClientProfile = 0x807C0000,
    // The sub-state machine is not currently active.
    BadStateNotActive = 0x80BF0000,
    // An equivalent rule already exists.
    BadAlreadyExists = 0x81150000,
    // The server cannot process the request because it is too busy.
    BadTcpServerTooBusy = 0x807D0000,
    // The type of the message specified in the header invalid.
    BadTcpMessageTypeInvalid = 0x807E0000,
    // The SecureChannelId and/or TokenId are not currently in use.
    BadTcpSecureChannelUnknown = 0x807F0000,
    // The size of the message chunk specified in the header is too large.
    BadTcpMessageTooLarge = 0x80800000,
    // There are not enough resources to process the request.
    BadTcpNotEnoughResources = 0x80810000,
    // An internal error occurred.
    BadTcpInternalError = 0x80820000,
    // The server does not recognize the QueryString specified.
    BadTcpEndpointUrlInvalid = 0x80830000,
    // The request could not be sent because of a network interruption.
    BadRequestInterrupted = 0x80840000,
    // Timeout occurred while processing the request.
    BadRequestTimeout = 0x80850000,
    // The secure channel has been closed.
    BadSecureChannelClosed = 0x80860000,
    // The token has expired or is not recognized.
    BadSecureChannelTokenUnknown = 0x80870000,
    // The sequence number is not valid.
    BadSequenceNumberInvalid = 0x80880000,
    // The applications do not have compatible protocol versions.
    BadProtocolVersionUnsupported = 0x80BE0000,
    // There is a problem with the configuration that affects the usefulness of the value.
    BadConfigurationError = 0x80890000,
    // The variable should receive its value from another variable, but has never been configured to do so.
    BadNotConnected = 0x808A0000,
    // There has been a failure in the device/data source that generates the value that has affected the value.
    BadDeviceFailure = 0x808B0000,
    // There has been a failure in the sensor from which the value is derived by the device/data source.
    BadSensorFailure = 0x808C0000,
    // The source of the data is not operational.
    BadOutOfService = 0x808D0000,
    // The deadband filter is not valid.
    BadDeadbandFilterInvalid = 0x808E0000,
    // Communication to the data source has failed. The variable value is the last value that had a good quality.
    UncertainNoCommunicationLastUsableValue = 0x408F0000,
    // Whatever was updating this value has stopped doing so.
    UncertainLastUsableValue = 0x40900000,
    // The value is an operational value that was manually overwritten.
    UncertainSubstituteValue = 0x40910000,
    // The value is an initial value for a variable that normally receives its value from another variable.
    UncertainInitialValue = 0x40920000,
    // The value is at one of the sensor limits.
    UncertainSensorNotAccurate = 0x40930000,
    // The value is outside of the range of values defined for this parameter.
    UncertainEngineeringUnitsExceeded = 0x40940000,
    // The value is derived from multiple sources and has less than the required number of Good sources.
    UncertainSubNormal = 0x40950000,
    // The value has been overridden.
    GoodLocalOverride = 0x00960000,
    // This Condition refresh failed, a Condition refresh operation is already in progress.
    BadRefreshInProgress = 0x80970000,
    // This condition has already been disabled.
    BadConditionAlreadyDisabled = 0x80980000,
    // This condition has already been enabled.
    BadConditionAlreadyEnabled = 0x80CC0000,
    // Property not available, this condition is disabled.
    BadConditionDisabled = 0x80990000,
    // The specified event id is not recognized.
    BadEventIdUnknown = 0x809A0000,
    // The event cannot be acknowledged.
    BadEventNotAcknowledgeable = 0x80BB0000,
    // The dialog condition is not active.
    BadDialogNotActive = 0x80CD0000,
    // The response is not valid for the dialog.
    BadDialogResponseInvalid = 0x80CE0000,
    // The condition branch has already been acknowledged.
    BadConditionBranchAlreadyAcked = 0x80CF0000,
    // The condition branch has already been confirmed.
    BadConditionBranchAlreadyConfirmed = 0x80D00000,
    // The condition has already been shelved.
    BadConditionAlreadyShelved = 0x80D10000,
    // The condition is not currently shelved.
    BadConditionNotShelved = 0x80D20000,
    // The shelving time not within an acceptable range.
    BadShelvingTimeOutOfRange = 0x80D30000,
    // No data exists for the requested time range or event filter.
    BadNoData = 0x809B0000,
    // No data found to provide upper or lower bound value.
    BadBoundNotFound = 0x80D70000,
    // The server cannot retrieve a bound for the variable.
    BadBoundNotSupported = 0x80D80000,
    // Data is missing due to collection started/stopped/lost.
    BadDataLost = 0x809D0000,
    // Expected data is unavailable for the requested time range due to an un-mounted volume, an off-line archive or tape, or similar reason for temporary unavailability.
    BadDataUnavailable = 0x809E0000,
    // The data or event was not successfully inserted because a matching entry exists.
    BadEntryExists = 0x809F0000,
    // The data or event was not successfully updated because no matching entry exists.
    BadNoEntryExists = 0x80A00000,
    // The client requested history using a timestamp format the server does not support (i.e requested ServerTimestamp when server only supports SourceTimestamp).
    BadTimestampNotSupported = 0x80A10000,
    // The data or event was successfully inserted into the historical database.
    GoodEntryInserted = 0x00A20000,
    // The data or event field was successfully replaced in the historical database.
    GoodEntryReplaced = 0x00A30000,
    // The value is derived from multiple values and has less than the required number of Good values.
    UncertainDataSubNormal = 0x40A40000,
    // No data exists for the requested time range or event filter.
    GoodNoData = 0x00A50000,
    // More data is available in the time range beyond the number of values requested.
    GoodMoreData = 0x00A60000,
    // The requested number of Aggregates does not match the requested number of NodeIds.
    BadAggregateListMismatch = 0x80D40000,
    // The requested Aggregate is not support by the server.
    BadAggregateNotSupported = 0x80D50000,
    // The aggregate value could not be derived due to invalid data inputs.
    BadAggregateInvalidInputs = 0x80D60000,
    // The aggregate configuration is not valid for specified node.
    BadAggregateConfigurationRejected = 0x80DA0000,
    // The request specifies fields which are not valid for the EventType or cannot be saved by the historian.
    GoodDataIgnored = 0x00D90000,
    // The request was rejected by the server because it did not meet the criteria set by the server.
    BadRequestNotAllowed = 0x80E40000,
    // The request has not been processed by the server yet.
    BadRequestNotComplete = 0x81130000,
    // The operation is not allowed because a transaction is in progress.
    BadTransactionPending = 0x80E80000,
    // The device identity needs a ticket before it can be accepted.
    BadTicketRequired = 0x811F0000,
    // The device identity needs a ticket before it can be accepted.
    BadTicketInvalid = 0x81200000,
    // The requested operation is not allowed, because the Node is locked by a different application.
    BadLocked = 0x80E90000,
    // The value does not come from the real source and has been edited by the server.
    GoodEdited = 0x00DC0000,
    // There was an error in execution of these post-actions.
    GoodPostActionFailed = 0x00DD0000,
    // The related EngineeringUnit has been changed but the Variable Value is still provided based on the previous unit.
    UncertainDominantValueChanged = 0x40DE0000,
    // A dependent value has been changed but the change has not been applied to the device.
    GoodDependentValueChanged = 0x00E00000,
    // The related EngineeringUnit has been changed but this change has not been applied to the device. The Variable Value is still dependent on the previous unit but its status is currently Bad.
    BadDominantValueChanged = 0x80E10000,
    // A dependent value has been changed but the change has not been applied to the device. The quality of the dominant variable is uncertain.
    UncertainDependentValueChanged = 0x40E20000,
    // A dependent value has been changed but the change has not been applied to the device. The quality of the dominant variable is Bad.
    BadDependentValueChanged = 0x80E30000,
    // It is delivered with a dominant Variable value when a dependent Variable has changed but the change has not been applied.
    GoodEdited_DependentValueChanged = 0x01160000,
    // It is delivered with a dependent Variable value when a dominant Variable has changed but the change has not been applied.
    GoodEdited_DominantValueChanged = 0x01170000,
    // It is delivered with a dependent Variable value when a dominant or dependent Variable has changed but change has not been applied.
    GoodEdited_DominantValueChanged_DependentValueChanged = 0x01180000,
    // It is delivered with a Variable value when Variable has changed but the value is not legal.
    BadEdited_OutOfRange = 0x81190000,
    // It is delivered with a Variable value when a source Variable has changed but the value is not legal.
    BadInitialValue_OutOfRange = 0x811A0000,
    // It is delivered with a dependent Variable value when a dominant Variable has changed and the value is not legal.
    BadOutOfRange_DominantValueChanged = 0x811B0000,
    // It is delivered with a dependent Variable value when a dominant Variable has changed, the value is not legal and the change has not been applied.
    BadEdited_OutOfRange_DominantValueChanged = 0x811C0000,
    // It is delivered with a dependent Variable value when a dominant or dependent Variable has changed and the value is not legal.
    BadOutOfRange_DominantValueChanged_DependentValueChanged = 0x811D0000,
    // It is delivered with a dependent Variable value when a dominant or dependent Variable has changed, the value is not legal and the change has not been applied.
    BadEdited_OutOfRange_DominantValueChanged_DependentValueChanged = 0x811E0000,
    // The communication layer has raised an event.
    GoodCommunicationEvent = 0x00A70000,
    // The system is shutting down.
    GoodShutdownEvent = 0x00A80000,
    // The operation is not finished and needs to be called again.
    GoodCallAgain = 0x00A90000,
    // A non-critical timeout occurred.
    GoodNonCriticalTimeout = 0x00AA0000,
    // One or more arguments are invalid.
    BadInvalidArgument = 0x80AB0000,
    // Could not establish a network connection to remote server.
    BadConnectionRejected = 0x80AC0000,
    // The server has disconnected from the client.
    BadDisconnect = 0x80AD0000,
    // The network connection has been closed.
    BadConnectionClosed = 0x80AE0000,
    // The operation cannot be completed because the object is closed, uninitialized or in some other invalid state.
    BadInvalidState = 0x80AF0000,
    // Cannot move beyond end of the stream.
    BadEndOfStream = 0x80B00000,
    // No data is currently available for reading from a non-blocking stream.
    BadNoDataAvailable = 0x80B10000,
    // The asynchronous operation is waiting for a response.
    BadWaitingForResponse = 0x80B20000,
    // The asynchronous operation was abandoned by the caller.
    BadOperationAbandoned = 0x80B30000,
    // The stream did not return all data requested (possibly because it is a non-blocking stream).
    BadExpectedStreamToBlock = 0x80B40000,
    // Non blocking behaviour is required and the operation would block.
    BadWouldBlock = 0x80B50000,
    // A value had an invalid syntax.
    BadSyntaxError = 0x80B60000,
    // The operation could not be finished because all available connections are in use.
    BadMaxConnectionsReached = 0x80B70000,
    // The value may not be accurate because the transducer is in manual mode.
    UncertainTransducerInManual = 0x42080000,
    // The value is simulated.
    UncertainSimulatedValue = 0x42090000,
    // The value may not be accurate due to a sensor calibration fault.
    UncertainSensorCalibration = 0x420A0000,
    // The value may not be accurate due to a configuration issue.
    UncertainConfigurationError = 0x420F0000,
    // The value source supports cascade handshaking and the value has been Initialized based on an initialization request from a cascade secondary.
    GoodCascadeInitializationAcknowledged = 0x04010000,
    // The value source supports cascade handshaking and is requesting initialization of a cascade primary.
    GoodCascadeInitializationRequest = 0x04020000,
    // The value source supports cascade handshaking, however, the source’s current state does not allow for cascade.
    GoodCascadeNotInvited = 0x04030000,
    // The value source supports cascade handshaking, however, the source has not selected the corresponding cascade primary for use.
    GoodCascadeNotSelected = 0x04040000,
    // There is a fault state condition active in the value source.
    GoodFaultStateActive = 0x04070000,
    // A fault state condition is being requested of the destination.
    GoodInitiateFaultState = 0x04080000,
    // The value is accurate, and the signal source supports cascade handshaking.
    GoodCascade = 0x04090000,
    // The DataSet specified for the DataSetWriter creation is invalid.
    BadDataSetIdInvalid = 0x80E70000,
} OpcUa_StatusCode;

#endif /* status_code_h */
