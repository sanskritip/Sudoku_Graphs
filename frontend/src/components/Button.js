import React from 'react';

function Button ({text}) {
    const handleClick = () => {}
    return (

            <a
                onClick = {handleClick}
                className = "button"
            >
                {text}
            </a>
    )
}

export default Button