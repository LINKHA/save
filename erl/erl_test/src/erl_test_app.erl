%%%-------------------------------------------------------------------
%% @doc erl_test public API
%% @end
%%%-------------------------------------------------------------------

-module(erl_test_app).

-behaviour(application).

-export([start/0, start/2, stop/1]).

start() ->
    A = 10,
    B = 20,
    start(A, B).

start(_StartType, _StartArgs) ->
    erl_test_sup:start_link().

stop(_State) ->
    ok.

%% internal functions
