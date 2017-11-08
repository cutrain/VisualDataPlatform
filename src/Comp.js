import React, { Component } from 'react';
import {Paper} from 'material-ui';
import ComponentContainer from './component/ComponentContainer.js'

export default class extends Component {
  constructor() {
    super();
    this.state = {

    };
  }
  render() {
    return (
      <div className="container">
        <Paper>
          <div className="listContainer">

          </div>
        </Paper>
      </div>
    )
  }
}
