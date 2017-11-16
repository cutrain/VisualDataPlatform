import React, {Component} from 'react';
import {Paper} from 'material-ui';

export default class extends Component {
  constructor() {
    super();
  }
  render() {
    return (
      <div className="container">
        <Paper>
          <div className="listContainer">
            {this.props.children}
          </div>
        </Paper>
      </div>
    )
  }
}
