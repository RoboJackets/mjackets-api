.. _delay:

Delay
#####

.. doxygenfile:: Delay.hpp
   :project: mjackets-api

Example Usage:
**************

.. code-block:: cpp

    while(1)
    {
        led1.Toggle();
        DelayMs(100)    // wait 100 milliseconds
        led2.Toggle();
        DelayUs(1000);  // wait for 1000 microseconds
    }
    