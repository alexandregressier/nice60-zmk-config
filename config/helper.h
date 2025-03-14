/* KP_WITH_MOD_SEQUENCE */

#if !defined KP_WITH_MOD_SEQUENCE_WAIT_MS
	#define KP_WITH_MOD_SEQUENCE_WAIT_MS 25
#endif
#if !defined KP_WITH_MOD_SEQUENCE_TAP_MS
	#define KP_WITH_MOD_SEQUENCE_TAP_MS 0
#endif

#define KP_WITH_MOD_SEQUENCE(NAME, MOD) \
	ZMK_MACRO_ONE_PARAM(NAME, \
		wait-ms = <KP_WITH_MOD_SEQUENCE_WAIT_MS>; \
		tap-ms = <KP_WITH_MOD_SEQUENCE_TAP_MS>; \
		bindings \
		= <&macro_press &kp MOD> \
		, <&macro_param_1to1> \
		, <&macro_tap &kp MACRO_PLACEHOLDER> \
		, <&macro_release &kp MOD>; \
	)

/* MAKE_HOLD_TAP */

#if !defined MAKE_HOLD_TAP_TERM_MS
    #define MAKE_HOLD_TAP_TERM_MS 180
#endif
#if !defined MAKE_HOLD_TAP_QUICK_TAP_MS
    #define MAKE_HOLD_TAP_QUICK_TAP_MS 280
#endif
#if !defined MAKE_HOLD_TAP_IDLE_MS
    #define MAKE_HOLD_TAP_IDLE_MS 200
#endif

#define MAKE_HOLD_TAP(...) CONCAT(MAKE_HOLD_TAP_, VARGS(__VA_ARGS__))(__VA_ARGS__)
#define MAKE_HOLD_TAP_3(NAME, HOLD, TAP) \
    MAKE_HOLD_TAP_4(NAME, HOLD, TAP, MAKE_HOLD_TAP_TERM_MS)
#define MAKE_HOLD_TAP_4(NAME, HOLD, TAP, TERM_MS) \
    MAKE_HOLD_TAP_5(NAME, HOLD, TAP, TERM_MS, MAKE_HOLD_TAP_QUICK_TAP_MS)
#define MAKE_HOLD_TAP_5(NAME, HOLD, TAP, TERM_MS, QUICK_TAP_MS) \
    MAKE_HOLD_TAP_6(NAME, HOLD, TAP, TERM_MS, QUICK_TAP_MS, MAKE_HOLD_TAP_IDLE_MS)
#define MAKE_HOLD_TAP_6(NAME, HOLD, TAP, TERM_MS, QUICK_TAP_MS, IDLE_MS) \
    ZMK_HOLD_TAP(NAME, \
		flavor = "tap-preferred"; \
		tapping-term-ms = <TERM_MS>; \
		quick-tap-ms = <QUICK_TAP_MS>; \
		require-prior-idle-ms = <IDLE_MS>; \
		bindings = <HOLD>, <TAP>; \
 	)
