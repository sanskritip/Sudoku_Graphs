import ROUTES from "./api_routes";
import axios from 'axios';

const generate_puzzle = async () => {
    var resp = null;
    await axios.get(ROUTES.generate)
    .then(response => {
            resp = JSON.parse(response.data.data)
            console.log(resp)
            
        })
    .catch(e =>{
            console.log("ERROR occured",e)
        })
    return resp
}

const API = {
    generate_puzzle
}

export default API;