/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6 at Thu Jun  9 14:18:28 2022. */

#ifndef PB_WIPPERSNAPPER_SIGNAL_V1_WIPPERSNAPPER_SIGNAL_V1_SIGNAL_PB_H_INCLUDED
#define PB_WIPPERSNAPPER_SIGNAL_V1_WIPPERSNAPPER_SIGNAL_V1_SIGNAL_PB_H_INCLUDED
#include <pb.h>
#include "nanopb/nanopb.pb.h"
#include "wippersnapper/pin/v1/pin.pb.h"
#include "wippersnapper/i2c/v1/i2c.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _wippersnapper_signal_v1_CreateSignalRequest { 
    pb_callback_t cb_payload;
    pb_size_t which_payload;
    union {
        /* Create, update or remove a GPIO pin */
        wippersnapper_pin_v1_ConfigurePinRequests pin_configs;
        /* Update a pin's state */
        wippersnapper_pin_v1_PinEvents pin_events;
        /* Create, update or remove a PWM output pin */
        wippersnapper_pin_v1_ConfigurePWMPinRequests pwm_pin_config;
        /* Write duty cycle to a PWM output pin */
        wippersnapper_pin_v1_PWMPinEvents pwm_pin_event;
        /* Update a pins state */
        wippersnapper_pin_v1_PinEvent pin_event;
    } payload;
} wippersnapper_signal_v1_CreateSignalRequest;

/* *
 I2CRequest represents the broker's request for a specific i2c command to a device. */
typedef struct _wippersnapper_signal_v1_I2CRequest { 
    pb_callback_t cb_payload;
    pb_size_t which_payload;
    union {
        wippersnapper_i2c_v1_I2CBusScanRequest req_i2c_scan;
        wippersnapper_i2c_v1_I2CBusSetFrequency req_i2c_set_freq;
        wippersnapper_i2c_v1_I2CDeviceInitRequest req_i2c_device_init;
        wippersnapper_i2c_v1_I2CDeviceDeinitRequest req_i2c_device_deinit;
        wippersnapper_i2c_v1_I2CDeviceUpdateRequest req_i2c_device_update;
        wippersnapper_i2c_v1_I2CDeviceInitRequests req_i2c_device_init_requests;
    } payload;
} wippersnapper_signal_v1_I2CRequest;

/* *
 I2CResponse represents the device's response to an I2C-specific message from IO. */
typedef struct _wippersnapper_signal_v1_I2CResponse { 
    pb_callback_t cb_payload;
    pb_size_t which_payload;
    union {
        wippersnapper_i2c_v1_I2CBusScanResponse resp_i2c_scan;
        wippersnapper_i2c_v1_I2CDeviceInitResponse resp_i2c_device_init;
        wippersnapper_i2c_v1_I2CDeviceDeinitResponse resp_i2c_device_deinit;
        wippersnapper_i2c_v1_I2CDeviceUpdateResponse resp_i2c_device_update;
        wippersnapper_i2c_v1_I2CDeviceEvent resp_i2c_device_event;
    } payload;
} wippersnapper_signal_v1_I2CResponse;

/* *
 Response from a signal message payload (device->broker) */
typedef struct _wippersnapper_signal_v1_SignalResponse { 
    pb_size_t which_payload;
    union {
        bool configuration_complete; /* * True if a device successfully completed a ConfigurePinRequests message, False otherwise. */
    } payload;
} wippersnapper_signal_v1_SignalResponse;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define wippersnapper_signal_v1_I2CRequest_init_default {{{NULL}, NULL}, 0, {wippersnapper_i2c_v1_I2CBusScanRequest_init_default}}
#define wippersnapper_signal_v1_I2CResponse_init_default {{{NULL}, NULL}, 0, {wippersnapper_i2c_v1_I2CBusScanResponse_init_default}}
#define wippersnapper_signal_v1_CreateSignalRequest_init_default {{{NULL}, NULL}, 0, {wippersnapper_pin_v1_ConfigurePinRequests_init_default}}
#define wippersnapper_signal_v1_SignalResponse_init_default {0, {0}}
#define wippersnapper_signal_v1_I2CRequest_init_zero {{{NULL}, NULL}, 0, {wippersnapper_i2c_v1_I2CBusScanRequest_init_zero}}
#define wippersnapper_signal_v1_I2CResponse_init_zero {{{NULL}, NULL}, 0, {wippersnapper_i2c_v1_I2CBusScanResponse_init_zero}}
#define wippersnapper_signal_v1_CreateSignalRequest_init_zero {{{NULL}, NULL}, 0, {wippersnapper_pin_v1_ConfigurePinRequests_init_zero}}
#define wippersnapper_signal_v1_SignalResponse_init_zero {0, {0}}

/* Field tags (for use in manual encoding/decoding) */
#define wippersnapper_signal_v1_CreateSignalRequest_pin_configs_tag 6
#define wippersnapper_signal_v1_CreateSignalRequest_pin_events_tag 7
#define wippersnapper_signal_v1_CreateSignalRequest_pwm_pin_config_tag 10
#define wippersnapper_signal_v1_CreateSignalRequest_pwm_pin_event_tag 12
#define wippersnapper_signal_v1_CreateSignalRequest_pin_event_tag 15
#define wippersnapper_signal_v1_I2CRequest_req_i2c_scan_tag 2
#define wippersnapper_signal_v1_I2CRequest_req_i2c_set_freq_tag 3
#define wippersnapper_signal_v1_I2CRequest_req_i2c_device_init_tag 4
#define wippersnapper_signal_v1_I2CRequest_req_i2c_device_deinit_tag 5
#define wippersnapper_signal_v1_I2CRequest_req_i2c_device_update_tag 6
#define wippersnapper_signal_v1_I2CRequest_req_i2c_device_init_requests_tag 7
#define wippersnapper_signal_v1_I2CResponse_resp_i2c_scan_tag 2
#define wippersnapper_signal_v1_I2CResponse_resp_i2c_device_init_tag 3
#define wippersnapper_signal_v1_I2CResponse_resp_i2c_device_deinit_tag 4
#define wippersnapper_signal_v1_I2CResponse_resp_i2c_device_update_tag 5
#define wippersnapper_signal_v1_I2CResponse_resp_i2c_device_event_tag 6
#define wippersnapper_signal_v1_SignalResponse_configuration_complete_tag 1

/* Struct field encoding specification for nanopb */
#define wippersnapper_signal_v1_I2CRequest_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,req_i2c_scan,payload.req_i2c_scan),   2) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,req_i2c_set_freq,payload.req_i2c_set_freq),   3) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,req_i2c_device_init,payload.req_i2c_device_init),   4) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,req_i2c_device_deinit,payload.req_i2c_device_deinit),   5) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,req_i2c_device_update,payload.req_i2c_device_update),   6) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,req_i2c_device_init_requests,payload.req_i2c_device_init_requests),   7)
#define wippersnapper_signal_v1_I2CRequest_CALLBACK NULL
#define wippersnapper_signal_v1_I2CRequest_DEFAULT NULL
#define wippersnapper_signal_v1_I2CRequest_payload_req_i2c_scan_MSGTYPE wippersnapper_i2c_v1_I2CBusScanRequest
#define wippersnapper_signal_v1_I2CRequest_payload_req_i2c_set_freq_MSGTYPE wippersnapper_i2c_v1_I2CBusSetFrequency
#define wippersnapper_signal_v1_I2CRequest_payload_req_i2c_device_init_MSGTYPE wippersnapper_i2c_v1_I2CDeviceInitRequest
#define wippersnapper_signal_v1_I2CRequest_payload_req_i2c_device_deinit_MSGTYPE wippersnapper_i2c_v1_I2CDeviceDeinitRequest
#define wippersnapper_signal_v1_I2CRequest_payload_req_i2c_device_update_MSGTYPE wippersnapper_i2c_v1_I2CDeviceUpdateRequest
#define wippersnapper_signal_v1_I2CRequest_payload_req_i2c_device_init_requests_MSGTYPE wippersnapper_i2c_v1_I2CDeviceInitRequests

#define wippersnapper_signal_v1_I2CResponse_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,resp_i2c_scan,payload.resp_i2c_scan),   2) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,resp_i2c_device_init,payload.resp_i2c_device_init),   3) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,resp_i2c_device_deinit,payload.resp_i2c_device_deinit),   4) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,resp_i2c_device_update,payload.resp_i2c_device_update),   5) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,resp_i2c_device_event,payload.resp_i2c_device_event),   6)
#define wippersnapper_signal_v1_I2CResponse_CALLBACK NULL
#define wippersnapper_signal_v1_I2CResponse_DEFAULT NULL
#define wippersnapper_signal_v1_I2CResponse_payload_resp_i2c_scan_MSGTYPE wippersnapper_i2c_v1_I2CBusScanResponse
#define wippersnapper_signal_v1_I2CResponse_payload_resp_i2c_device_init_MSGTYPE wippersnapper_i2c_v1_I2CDeviceInitResponse
#define wippersnapper_signal_v1_I2CResponse_payload_resp_i2c_device_deinit_MSGTYPE wippersnapper_i2c_v1_I2CDeviceDeinitResponse
#define wippersnapper_signal_v1_I2CResponse_payload_resp_i2c_device_update_MSGTYPE wippersnapper_i2c_v1_I2CDeviceUpdateResponse
#define wippersnapper_signal_v1_I2CResponse_payload_resp_i2c_device_event_MSGTYPE wippersnapper_i2c_v1_I2CDeviceEvent

#define wippersnapper_signal_v1_CreateSignalRequest_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pin_configs,payload.pin_configs),   6) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pin_events,payload.pin_events),   7) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_pin_config,payload.pwm_pin_config),  10) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_pin_event,payload.pwm_pin_event),  12) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pin_event,payload.pin_event),  15)
#define wippersnapper_signal_v1_CreateSignalRequest_CALLBACK NULL
#define wippersnapper_signal_v1_CreateSignalRequest_DEFAULT NULL
#define wippersnapper_signal_v1_CreateSignalRequest_payload_pin_configs_MSGTYPE wippersnapper_pin_v1_ConfigurePinRequests
#define wippersnapper_signal_v1_CreateSignalRequest_payload_pin_events_MSGTYPE wippersnapper_pin_v1_PinEvents
#define wippersnapper_signal_v1_CreateSignalRequest_payload_pwm_pin_config_MSGTYPE wippersnapper_pin_v1_ConfigurePWMPinRequests
#define wippersnapper_signal_v1_CreateSignalRequest_payload_pwm_pin_event_MSGTYPE wippersnapper_pin_v1_PWMPinEvents
#define wippersnapper_signal_v1_CreateSignalRequest_payload_pin_event_MSGTYPE wippersnapper_pin_v1_PinEvent

#define wippersnapper_signal_v1_SignalResponse_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,configuration_complete,payload.configuration_complete),   1)
#define wippersnapper_signal_v1_SignalResponse_CALLBACK NULL
#define wippersnapper_signal_v1_SignalResponse_DEFAULT NULL

extern const pb_msgdesc_t wippersnapper_signal_v1_I2CRequest_msg;
extern const pb_msgdesc_t wippersnapper_signal_v1_I2CResponse_msg;
extern const pb_msgdesc_t wippersnapper_signal_v1_CreateSignalRequest_msg;
extern const pb_msgdesc_t wippersnapper_signal_v1_SignalResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define wippersnapper_signal_v1_I2CRequest_fields &wippersnapper_signal_v1_I2CRequest_msg
#define wippersnapper_signal_v1_I2CResponse_fields &wippersnapper_signal_v1_I2CResponse_msg
#define wippersnapper_signal_v1_CreateSignalRequest_fields &wippersnapper_signal_v1_CreateSignalRequest_msg
#define wippersnapper_signal_v1_SignalResponse_fields &wippersnapper_signal_v1_SignalResponse_msg

/* Maximum encoded size of messages (where known) */
#if defined(wippersnapper_i2c_v1_I2CDeviceInitRequests_size)
union wippersnapper_signal_v1_I2CRequest_payload_size_union {char f7[(6 + wippersnapper_i2c_v1_I2CDeviceInitRequests_size)]; char f0[227];};
#endif
#if defined(wippersnapper_pin_v1_ConfigurePinRequests_size) && defined(wippersnapper_pin_v1_PinEvents_size) && defined(wippersnapper_pin_v1_ConfigurePWMPinRequests_size) && defined(wippersnapper_pin_v1_PWMPinEvents_size)
union wippersnapper_signal_v1_CreateSignalRequest_payload_size_union {char f6[(6 + wippersnapper_pin_v1_ConfigurePinRequests_size)]; char f7[(6 + wippersnapper_pin_v1_PinEvents_size)]; char f10[(6 + wippersnapper_pin_v1_ConfigurePWMPinRequests_size)]; char f12[(6 + wippersnapper_pin_v1_PWMPinEvents_size)]; char f0[21];};
#endif
#if defined(wippersnapper_i2c_v1_I2CDeviceInitRequests_size)
#define wippersnapper_signal_v1_I2CRequest_size  (0 + sizeof(union wippersnapper_signal_v1_I2CRequest_payload_size_union))
#endif
#define wippersnapper_signal_v1_I2CResponse_size 725
#define wippersnapper_signal_v1_SignalResponse_size 2
#if defined(wippersnapper_pin_v1_ConfigurePinRequests_size) && defined(wippersnapper_pin_v1_PinEvents_size) && defined(wippersnapper_pin_v1_ConfigurePWMPinRequests_size) && defined(wippersnapper_pin_v1_PWMPinEvents_size)
#define wippersnapper_signal_v1_CreateSignalRequest_size (0 + sizeof(union wippersnapper_signal_v1_CreateSignalRequest_payload_size_union))
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
