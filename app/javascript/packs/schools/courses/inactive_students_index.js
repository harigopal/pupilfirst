import "schools/founders/index.css";
import "schools/shared/shared.css";
import * as React from "react";
import * as ReactDOM from "react-dom";
import {jsComponent} from "../../../schools/founders/components/SA_InactiveStudentsPanel.bs";


const root = document.getElementById("sa-students-panel");
const props = JSON.parse(root.dataset.props);
ReactDOM.render(React.createElement(jsComponent, props), root);

