.. _digital_in:

DigitalIn
#########

.. doxygenclass:: DigitalIn
   :project: mjackets-api
   :members:

Example Usage:
**************

.. code-block:: cpp

    DigitalIn myInput(PIN_E5, PullNone);
    
    if (myInput.read())
    {
        print("myInput is high!");
    }
    else
    {
        print("myInput is low!");
    }

.. note::
    Make sure that you have initialized the GPIO peripheral clock for
    your GPIO port before initializing the pin as an input. 