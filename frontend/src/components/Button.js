import React from 'react';

function Button ({text,onClick}) {
    return (

            <a
                onClick = {onClick}
                className = "button"
            >
                {text}
            </a>
    )
}

export default Button