#!/bin/bash
function first_arg()
{
    return $1
}
first_arg $1
echo "$?"