%%%-------------------------------------------------------------------
%% @doc erl_umbrella_test public API
%% @end
%%%-------------------------------------------------------------------

-module(erl_umbrella_test_app).

-behaviour(application).

-export([start/2, stop/1]).

start(_StartType, _StartArgs) ->
    erl_umbrella_test_sup:start_link().

stop(_State) ->
    ok.

%% internal functions
